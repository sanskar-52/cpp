// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
// (i.e., from left to right, then right to left for the next level and alternate between).

// Input : root = [ 3, 9, 20, null, null, 15, 7 ]
// Output : [ [3], [ 20, 9 ], [ 15, 7 ] ]

#include "../TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Performs zigzag (spiral) level order traversal of a binary tree.
 *
 * This function traverses the binary tree level by level, alternating the direction
 * of traversal at each level (left-to-right, then right-to-left, and so on).
 *
 * @param root Pointer to the root node of the binary tree.
 * @return A vector of vectors, where each inner vector contains the values of nodes
 *         at a particular level in zigzag order.
 */
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  if (root == nullptr)
    return ans;

  queue<TreeNode *> q;
  q.push(root);
  bool leftToRight = true;

  while (!q.empty())
  {
    int size = q.size();
    vector<int> level(size);

    for (int i = 0; i < size; i++)
    {
      TreeNode *front = q.front();
      q.pop();

      int index = (leftToRight) ? i : size - 1 - i;
      level[index] = front->val;

      if (front->left)
      {
        q.push(front->left);
      }

      if (front->right)
      {
        q.push(front->right);
      }
    }
    leftToRight = !leftToRight;
    ans.push_back(level);
  }

  return ans;
}