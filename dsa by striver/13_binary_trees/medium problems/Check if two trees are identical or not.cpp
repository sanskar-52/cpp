// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// 🧩 Algorithm:
//
// Step 1️⃣: Start at the root node of both trees (node1 and node2).
//
// Step 2️⃣: Check if the values of the current nodes in both trees are equal.
//           → If not, return false.
//
// Step 3️⃣: Recursively check the left and then the right subtree
//           of the current node in both trees to see if they are identical.
//
// Step 4️⃣: If all the recursive checks return true,
//           then the trees are identical; otherwise, they are not.

#include "../TreeNode.h"
using namespace std;

bool isIdentical(TreeNode *p, TreeNode *q)
{
  // If both nodes are NULL,
  // they are identical
  if (p == NULL && q == NULL)
    return true;

  // If only one of the nodes is
  // NULL, they are not identical
  if (p == nullptr || q == nullptr)
    return false;

    return ((p->val == q->val) && isIdentical(p->left, q->left) && isIdentical(p->right, q->right));
}