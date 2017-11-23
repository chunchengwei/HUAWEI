//******************************************************************************
// File Name: tools.cpp
// Author: Chuncheng Wei
// Mail: weicc1989@gmail.com
// Created Time : Thu 23 Nov 2017 09:30:14 PM CST
// Last Modified: Thu 23 Nov 2017 10:31:01 PM CST
//******************************************************************************

#include "tools.h"
#include <cstring>
#include <cstdlib>

using namespace std;


vector<int> _readline_(char * line)
{
  vector<int> vl;
  char * pch;

  pch = strtok(line, " ");
  while(pch != NULL) {
    vl.push_back(atoi(pch));
    pch = strtok(NULL, " ");
  }
  return vl;
}

vector< vector<int> > TOOLS::ParaseFile(char* inLines[MAX_IN_NUM], int inLineNum)
{
  vector<vector<int> > data;

  // 1st line: [network nodes, links, consumption nodes]
  data.push_back(_readline_(inLines[0]));
  int nLinks  = data[0][1],
      nCnodes = data[0][2];

  // 3st line: [cost]
  data.push_back(_readline_(inLines[2]));

  // 5st ~ links+4: [start ID, end ID, bandwidth, fee]
  int n = 0;
  while(n < nLinks) {
    data.push_back(_readline_(inLines[n+4]));
    n++;
  }

  // links+5 ~ end: [consumption nodes ID, adjacent network node ID, bandwidth requirement]
  n = 0;
  while(n < nCnodes) {
    data.push_back(_readline_(inLines[n+5+nLinks]));
    n++;
  }

  return data;
}
