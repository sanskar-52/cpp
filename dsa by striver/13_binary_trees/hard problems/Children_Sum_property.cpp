// Problem Statement: Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property.
// The Children Sum Property in a binary tree states that for every node,
// the sum of its children's values (if they exist) should be equal to the node's value. If a child is missing,
// it is considered as having a value of 0.

// The node values can be increased by any positive integer any number of times, but decrementing any node value is not allowed.

#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

class Solution
{
public:
  void changeTree(TreeNode *root)
  {
    if (root == NULL)
      return;

    // calculating the sum of child's val;
    int child = 0;
    if (root->left)
      child += root->left->val;
    if (root->right)
      child += root->right->val;

    // checking the child is greater than root->val or vice-versa.
    if (child >= root->val)
      root->val = child;
    else
    {
      if (root->left)
        root->left->val = root->val;
      if (root->right)
        root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left)
      total += root->left->val;
    if (root->right)
      total += root->right->val;

    //
    if (root->left or root->right)
      root->val = total;
  }
};

void inorderTraversal(TreeNode *root)
{
  if (root == nullptr)
  {
    return;
  }
  inorderTraversal(root->left);
  cout << root->val << " ";
  inorderTraversal(root->right);
}
int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  Solution sol;

  // Print the inorder traversal
  // of tree before modification
  cout << "Binary Tree before modification: ";
  inorderTraversal(root);
  cout << endl;

  // Call the changeTree function
  // to modify the binary tree
  sol.changeTree(root);

  // Print the inorder traversal
  // after modification
  cout << "Binary Tree after Children Sum Property: ";
  inorderTraversal(root);
  cout << endl;

  return 0;
}
