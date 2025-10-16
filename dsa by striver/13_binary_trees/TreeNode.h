// TreeNode.h
#ifndef TREENODE_H // Header guard to prevent multiple inclusion
#define TREENODE_H

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  // Constructor
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif // TREENODE_H
