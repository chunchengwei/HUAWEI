//******************************************************************************
// File Name: graph.h
// Author: Chuncheng Wei
// Mail: weicc1989@gmail.com
// Created Time : Thu 23 Nov 2017 10:58:07 PM CST
// Last Modified: Fri 24 Nov 2017 06:20:07 AM CST
//******************************************************************************

#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <sstream>
#include "lib_io.h"


class GRAPH
{
  public:
    int nNnode; // network nodes number
    int nLinks; // links number
    int nCnode; // consumption nodes number

    int scost;  // cost of the video content server

    // links
    std::vector< std::pair<int, int> > LINKS;
    std::vector< int > BANDWIDTH;
    std::vector< int > FEE;

    // network nodes
    std::vector< std::vector<int> > FLOWOUT;

    // consumption nodes
    std::vector< int > CNODES; // CNODES[adjacent network ID] = consumption nodes id
    std::vector< int > REQUIREMENT; // REQUIREMENT[adjacent network ID] = consumption nodes requirement

    // result
    std::vector< std::vector<int> > ALLPATH;

    GRAPH(char* inLines[MAX_IN_NUM], int inLineNum);

    void Print(std::vector<int> SNODES, std::vector<int> FLOWS, std::ostringstream & os);



  private:
    std::vector< int > _REQUIREMENT_; // REQUIREMENT[adjacent network ID] = consumption nodes requirement

    void _readline_(char * line, std::vector<int> & vl);
    void _digpath_(int root_node, std::vector<int> & FLOWS, std::vector<int> & path, std::vector<int> & root_flow);

};
#endif
