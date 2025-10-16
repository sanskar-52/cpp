#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int val)
  {
    data = val;
    left = right = nullptr;
  }
};

/**
 * @brief Performs level order traversal (breadth-first traversal) of a binary tree.
 *
 * This function traverses the binary tree level by level and returns a vector of vectors,
 * where each inner vector contains the node values at that particular level.
 *
 * @param root Pointer to the root node of the binary tree.
 * @return std::vector<std::vector<int>> A vector containing vectors of node values for each level.
 *         Returns an empty vector if the tree is empty.
 */
vector<vector<int>> levelOrder(Node *root)
{
  vector<vector<int>> ans;
  if (root == nullptr)
    return ans;
  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++)
    {
      Node *front = q.front();
      q.pop();
      if (front->left != nullptr)
        q.push(front->left);
      if (front->right != nullptr)
        q.push(front->right);
      level.push_back(front->data);
    }

    ans.push_back(level);
  }
  return ans;
}

int main()
{
  return 0;
}