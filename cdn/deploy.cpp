#include "deploy.h"
#include "lib_io.h"
#include "lib_time.h"
#include "graph.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


void deploy_server(char* inLines[MAX_IN_NUM], int inLineNum, const char * const filename)
{
	assert(inLineNum < MAX_IN_NUM);

  // print input
	printf("line count %d\n", inLineNum);
	for (int i = 0; i < inLineNum; ++i)
	{
		printf("line %d=%s\n", i, inLines[i]);
	}

  // creat graph
  GRAPH graph(inLines, inLineNum);

  // cout<<graph.nNnode<<"\t"<<graph.nLinks<<"\t"<<graph.nCnode<<endl;
  // cout<<graph.scost<<endl;

  // cout<<"links:"<<endl;
  // for(unsigned i=0; i<graph.LINKS.size(); i++)
    // cout<<graph.LINKS[i].first<<"\t"<<graph.LINKS[i].second
      // <<"\t"<<graph.BANDWIDTH[i]<<"\t"<<graph.FEE[i]<<endl;

  // cout<<"network nodes:"<<endl;
  // for(unsigned i=0; i<graph.FLOWOUT.size(); i++) {
    // cout<<i<<": ";
    // for(unsigned j=0; j<graph.FLOWOUT[i].size(); j++)
      // cout<<graph.FLOWOUT[i][j]<<"\t";
    // cout << endl;
  // }

  // cout<<"consumption nodes:"<<endl;
  // for(unsigned i=0; i<graph.CNODES.size(); i++)
    // cout<<i<<"\t"<<graph.CNODES[i].first<<"\t"<<graph.CNODES[i].second<<endl;

  // cout<<"requirement"<<endl;
  // for(unsigned i=0; i<graph.REQUIREMENT.size(); i++)
    // cout<<i<<": "<<graph.REQUIREMENT[i]<<endl;




  vector<int> SNODES = {1,2,3};
  vector<int> FLOWS = {1,2,3};


  // output
  ostringstream os;
  graph.Print(SNODES, FLOWS, os);

  write_result(os.str().c_str(), filename);
}
