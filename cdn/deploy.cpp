#include "deploy.h"
#include "lib_io.h"
#include "lib_time.h"
#include "graph.h"
#include "simplex.h"
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
	// printf("line count %d\n", inLineNum);
	// for (int i = 0; i < inLineNum; ++i)
	// {
		// printf("line %d=%s\n", i, inLines[i]);
	// }

  // creat graph
  GRAPH graph(inLines, inLineNum);


  // calculate
  srand((int)time(0));
  calculator cal(graph);

  vector<int> SNODES = cal.SNODES;
  vector<int> FLOWS  = cal.FLOWS;

  // output
  ostringstream os;
  graph.Print(SNODES, FLOWS, os);

  write_result(os.str().c_str(), filename);
}
