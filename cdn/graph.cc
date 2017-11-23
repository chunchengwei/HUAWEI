//******************************************************************************
// File Name: graph.cpp
// Author: Chuncheng Wei
// Mail: weicc1989@gmail.com
// Created Time : Fri 24 Nov 2017 12:07:26 AM CST
// Last Modified: Fri 24 Nov 2017 06:21:39 AM CST
//******************************************************************************

#include "graph.h"
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

GRAPH::GRAPH(char* inLines[MAX_IN_NUM], int inLineNum)
{
  vector<int> vl;

  // 1st line: [network nodes, links, consumption nodes]
  _readline_(inLines[0], vl);

  nNnode = vl[0];
  nLinks = vl[1];
  nCnode = vl[2];

  // 3st line: [cost]
  _readline_(inLines[2], vl);

  scost = vl[0];

  // 5st ~ links+4: [start ID, end ID, bandwidth, fee]
  int nLinks_2side = 2 * nLinks;

  LINKS.resize(nLinks_2side);
  BANDWIDTH.resize(nLinks_2side);
  FEE.resize(nLinks_2side);

  int n = 0;
  while(n < nLinks) {

    _readline_(inLines[n+4], vl);

    if(vl[0] < vl[1]) {
      LINKS[n]                = make_pair(vl[0], vl[1]);
      LINKS[nLinks_2side-1-n] = make_pair(vl[1], vl[0]);

      BANDWIDTH[n]                = vl[2];
      BANDWIDTH[nLinks_2side-1-n] = vl[2];

      FEE[n]                = vl[3];
      FEE[nLinks_2side-1-n] = vl[3];
    }

    n++;
  }

  // links+5 ~ end: [consumption nodes ID, adjacent network node ID, bandwidth requirement]
  CNODES.resize(nNnode);
  REQUIREMENT.resize(nNnode);
  memset(&CNODES[0],     -1, sizeof(int)*nNnode);
  memset(&REQUIREMENT[0], 0, sizeof(int)*nNnode);

  n = 0;
  while(n < nCnode) {

    _readline_(inLines[n+5+nLinks], vl);

    CNODES[vl[1]] = n;
    REQUIREMENT[vl[1]] = vl[2];

    n++;
  }


}

void GRAPH::Print(std::vector<int> SNODES, std::vector<int> FLOWS, std::ostringstream & os)
{
  _REQUIREMENT_ = REQUIREMENT;
  ALLPATH.resize(0);

  for(unsigned i=0; i<SNODES.size(); i++) {
    vector<int> path;
    vector<int> root_flow;

    int SF = 0;
    for(unsigned j=0; j<FLOWOUT[SNODES[i]].size(); j++) {
      int id = FLOWOUT[SNODES[i]][j];
      SF += FLOWS[id];
    }
    root_flow.push_back(SF);

    _digpath_(SNODES[i], FLOWS, path, root_flow);
  }

  // print
  os << ALLPATH.size() << "\n\n";
  for(unsigned i=0; i<ALLPATH.size(); i++) {
    for(unsigned j=0; j<ALLPATH[i].size(); j++) {
        os << ALLPATH[i][j] << " ";
      os << "\n";
    }
  }
}

void GRAPH::_readline_(char * line, vector<int> & vl)
{
  vl.resize(0);
  char * pch;

  pch = strtok(line, " ");
  while(pch != NULL) {
    vl.push_back(atoi(pch));
    pch = strtok(NULL, " ");
  }
}

void GRAPH::_digpath_(int root_node, vector<int> & FLOWS, vector<int> & path, vector<int> & root_flow)
{
  path.push_back(root_node);

  // if connect consumption nodes
  if(CNODES[root_node] != -1)
  {
    path.push_back(CNODES[root_node]);
    if(root_flow.back() <= _REQUIREMENT_[root_node]) {
      _REQUIREMENT_[root_node] -= root_flow.back();
      path.push_back(root_flow.back());
      ALLPATH.push_back(path);
      path.pop_back();
      path.pop_back();
      root_flow.pop_back();
      return;
    }
    else
    {
      path.push_back(_REQUIREMENT_[root_node]);
      root_flow.back() -= _REQUIREMENT_[root_node];
      _REQUIREMENT_[root_node] = 0;
      ALLPATH.push_back(path);
      path.pop_back();
    }
  }

  // loop all flowout links, which has nozero flux
  for(unsigned i=0; i<FLOWOUT[root_node].size(); i++) {

    int id = FLOWOUT[root_node][i];

    if(FLOWS[id] != 0) {
      if(root_flow.back() > FLOWS[id]) {
        root_flow.back() -= FLOWS[id];
        root_flow.push_back(FLOWS[id]);
        _digpath_(LINKS[id].second, FLOWS, path, root_flow);
      }
      else {
        int temp = root_flow.back();
        root_flow.back() = 0;
        root_flow.push_back(temp);
        _digpath_(LINKS[id].second, FLOWS, path, root_flow);
        break;
      }
    }

  }
  path.pop_back();
  root_flow.pop_back();
}
