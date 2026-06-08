// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.

#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

class Solution
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    int width = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
      int n = q.size();
      int first = q.front().second;
      int last;
      for (int i = 0; i < n; i++)
      {

        auto it = q.front();
        TreeNode *front = it.first;
        int index = it.second;

        if (i == n - 1)
          last = index;

        if (front->left)
        {
          q.push({front->left, 2 * index});
        }
        if (front->right)
        {
          q.push({front->right, 2 * index + 1});
        }
        q.pop();
      }
      width = max(width, (last - first + 1));
    }

    return width;
  }
};