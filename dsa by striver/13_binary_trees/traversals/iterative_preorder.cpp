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
 * @brief Performs an iterative preorder traversal of a binary tree.
 *
 * This function traverses the binary tree in preorder (root, left, right) order
 * using a stack to avoid recursion. It returns a vector containing the node values
 * in preorder sequence.
 *
 * @param root Pointer to the root node of the binary tree.
 * @return std::vector<int> containing the preorder traversal of the tree.
 *
 * @note
 * Time Complexity: O(N), where N is the number of nodes in the binary tree.
 *                  Each node is visited exactly once.
 * Space Complexity: O(N), due to the stack and the output vector.
 *                   In the worst case (skewed tree), the stack may hold up to N nodes.
 */
vector<int> preOrderTraversal(Node *root)
{
  vector<int> preorder;
  if (root == NULL)
    return preorder;

  stack<Node *> st;
  st.push(root);

  while (!st.empty())
  {
    Node *uparWaala = st.top();
    preorder.push_back(uparWaala->data);
    st.pop();

    if (uparWaala->right != nullptr)
      st.push(uparWaala->right);
    if (uparWaala->left != nullptr)
      st.push(uparWaala->left);
  }

  return preorder;
};