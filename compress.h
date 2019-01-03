#ifndef COMPRESS_H
#define COMPRESS_H

#include<iostream>

struct NODE 
{
  int subtree;
  int parent;
  int current;
  int freq; //skip the leaf flag for now.
};

extern NODE LEAF[128]; //this.
extern NODE NODE_POOL[256];
extern NODE ROOT_NODE;
extern std::string PREFIX[130];
extern std::string input;
extern int DELETED[256];
extern int LEAF_TOP;
extern int POOL_TOP;
extern int DELETED_TOP;
extern int ROOTSUM;
extern int PREFIX_TOP;

void InitLeaves(std::string input, int count[]);
void PrintLeaves(NODE input[], int n);
void InjectPool();
void SortPool(NODE input[], int n);
int CombineNodes(); //combine two nodes.Returns 0 if root is not found, else returns root's current index.
void RefillPool();
void GenerateTree();
void ObtainPrefix(int n);
void PrintPrefix();
void ResolveOutput(std::string unique);
void PrintOutput();
#endif

