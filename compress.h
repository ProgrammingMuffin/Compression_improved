#ifndef COMPRESS_H
#define COMPRESS_H

#include<iostream>

struct NODE 
{
  char subtree;
  int parent;
  char current;
  int freq; //skip the leaf flag for now.
};

extern NODE LEAF[128]; //this.
extern NODE NODE_POOL[256];
extern NODE DELETED[256];
extern int LEAF_TOP;
extern int POOL_TOP;
extern int DEL_TOP;

void InitLeaves(std::string input, int count[]);
void PrintLeaves(NODE input[], int n);
void InjectPool();
void SortPool(NODE input[], int n); // this is the prototype use this in compress.cpp

#endif

