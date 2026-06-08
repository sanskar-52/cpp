// You are given the root of a binary tree, and your task is to return its top view.
// The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// first we are finding the width of the top view vector and then findind the index for root node in the top view vectoe
// we will use isFilled[] to check whether an index of the top view vector has been reached and the top view element is populated or not
// by doing BFS
class Solution
{
public:
  // this function will do DFS and find the l and r
  void findWidth(TreeNode *root, int pos, int &l, int &r)
  {
    if (root == nullptr)
      return;

    l = min(l, pos);
    r = max(r, pos);

    findWidth(root->left, pos - 1, l, r);
    findWidth(root->right, pos + 1, l, r);
  }

  vector<int> topView(TreeNode *root)
  {
    int l = 0;
    int r = 0;
    findWidth(root, 0, l, r);

    vector<int> top(r - l + 1);
    vector<bool> isFilled(r - l + 1);

    // now we will traverse the Binary Tree, to find top view elements
    // we need a queue for BFS

    queue<pair<TreeNode *, int>> q;
    q.push({root, -1 * l});

    while (!q.empty())
    {
      auto it = q.front();
      q.pop();

      TreeNode *temp = it.first;
      int pos = it.second;

      if (!isFilled[pos])
      {
        isFilled[pos] = true;
        top[pos] = temp->val;
      }

      if (temp->left)
      {
        q.push({temp->left, pos - 1});
      }

      if (temp->right)
      {
        q.push({temp->right, pos + 1});
      }
    }

    return top;
  }
};

// same logic as before but now we are traversing the binary tree with DFS

class Solution
{
public:
  void findWidth(TreeNode *root, int pos, int &l, int &r)
  {
    if (root == nullptr)
      return;

    l = min(l, pos);
    r = max(r, pos);

    findWidth(root->left, pos - 1, l, r);
    findWidth(root->right, pos + 1, l, r);
  }

  void traverse(TreeNode *root, int pos, int clvl, vector<int> &top, vector<int> &level)
  {
    if (root == nullptr)
      return;

    if (clvl < level[pos])
    {
      level[pos] = clvl;
      top[pos] = root->val;
    }

    traverse(root->left, pos - 1, clvl + 1, top, level);
    traverse(root->right, pos + 1, clvl + 1, top, level);
  }

  vector<int> topView(TreeNode *root)
  {
    int l = 0;
    int r = 0;
    findWidth(root, 0, l, r);

    vector<int> top(r - l + 1);
    vector<int> level(r - l + 1, INT_MAX);

    return top;
  }
};