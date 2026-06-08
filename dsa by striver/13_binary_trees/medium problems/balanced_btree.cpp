// have to check whether a binary tree is balanced or not.
/*
A balanced binary tree is a binary tree in which the height of the left and right subtrees of every node differ by no more than 1.
This ensures that the tree remains approximately balanced, preventing worst-case scenarios for operations like search, insert, and delete.
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;

  TreeNode(int val)
  {
    data = val;
    left = right = nullptr;
  }
};

// making a fucntion that will return -1 if the tree is not balanced.
// and returns the height if the tree is not balanced.

int height(TreeNode *root)
{
  if (root == nullptr)
    return 0;
  int lh = height(root->left);
  if (lh == -1)
  {
    return -1;
  }
  int rh = height(root->right);
  if (rh == -1)
  {
    return -1;
  }

  if (abs(lh - rh) > 1)
  {
    return -1;
  }

  return 1 + std::max(lh, rh);
}
