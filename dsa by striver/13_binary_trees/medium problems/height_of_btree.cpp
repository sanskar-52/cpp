// have to find the maximum depth or height of binary tree.
// either through recursion or level order traversal.

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

// using recursion.
int maxDepth(TreeNode *root)
{
  if (root == nullptr)
    return 0;

  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  return 1 + max(lh, rh);
}

// 🧱 Algorithm
//   If the tree is
//     empty(root == NULL),
//     return 0.
//   Create a queue and push the root node.
//   While the queue is not empty :
//   Get the number of nodes at the current level(size = q.size())
//   Process all nodes of this level(pop them and push their children).

//   After finishing one level,
//     increment depth by 1.

//   When the queue is empty,
//     depth will be the maximum depth.

// through traversal
int maxDepth(TreeNode *root)
{
  if (root == nullptr)
    return 0;

  queue<TreeNode *> q;
  q.push(root);
  int depth = 0;

  while (!q.empty())
  {
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
      TreeNode *front = q.front();
      q.pop();
      if (front->left != nullptr)
        q.push(front->left);
      if (front->right != nullptr)
        q.push(front->right);
    }
    depth++;
  }

  return depth;
}

int main()
{
  return 0;
}