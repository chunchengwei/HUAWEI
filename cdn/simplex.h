//=====================================================================
// 
//=====================================================================
#ifndef SIMPLEX_HEADER
#define SIMPLEX_HEADER
//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<list>
#include<math.h>
#include"graph.h"
using namespace std;

class calculator
{
  public:
//    int n_server;
//    int n_arc;  // arcs number
//    int n_node; // nodes number

    // input
    std::vector< int > limit;
    std::vector< int > cost;
    std::vector< int > demand;
    std::vector< std::vector<int> > node;
    std::vector< int > node_max;        // max flow of node
    std::vector< unsigned > node_sort;  // sort of max flow
    std::vector< unsigned > Cnode_sort;  // sort of max flow
    int dp_server; // cost of server
    int n_cnode;   // number of consumption node


    // result
    vector<int> SNODES;
    vector<int> FLOWS;

    // method

//    calculator(int nCNODE, int scost, vector<int> &cost, vector<int> &limit, vector<int> &demand, vector< vector<int> > &node);
    calculator(GRAPH graph);



  private:

    int _Nleast;   // minmal number of server
    int _AllDemand; // all demand
    int _mincost;
    std::vector< std::set<int> > _schema;
    std::set<int> _server;

    int _minfee(set<int> &server, vector<int> &answer);
    bool _findar(set<unsigned> ar, vector<unsigned> Cb);
    void _annealing(set<int> &server);

};

#endif
//=====================================================================


