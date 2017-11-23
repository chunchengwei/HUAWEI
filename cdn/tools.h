//******************************************************************************
// File Name: tools.h
// Author: Chuncheng Wei
// Mail: weicc1989@gmail.com
// Created Time : Thu 23 Nov 2017 09:25:41 PM CST
// Last Modified: Thu 23 Nov 2017 09:30:05 PM CST
//******************************************************************************

#ifndef _TOOLS_H
#define _TOOLS_H

#include <vector>
#include "lib_io.h"

namespace TOOLS
{
  std::vector<std::vector<int> > ParaseFile(char* inLines[MAX_IN_NUM], int inLineNum);

}
#endif
