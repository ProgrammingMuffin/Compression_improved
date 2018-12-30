#include <iostream>
#include "compress.h"
#include "manipulate.h"

std::string input = "KEBABBRO";

int main( )
{
  int i, n, count[100];
  std::string unique;
  unique = GetUnique(input);
  GetCount(input, count, unique);
  n = (int)unique.length();
  InitLeaves(unique, count);
  InjectPool();
  PrintLeaves(NODE_POOL, POOL_TOP);
  return 0;
}




//now what should i do