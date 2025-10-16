// left root right
// have to return a vector of inorder traversal

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

vector<int> inOrderTraversal(TreeNode *root)
{
  // for traversal we will be using stack.
  stack<TreeNode *> st;
  // to return the traversal data.
  vector<int> inorder;
  TreeNode *curr = root;

  while (curr != nullptr || !st.empty())
  {
    while (curr != nullptr)
    {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    inorder.push_back(curr->data);

    curr = curr->right;
  }
  return inorder;
}