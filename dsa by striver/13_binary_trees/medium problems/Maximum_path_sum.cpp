/**
 * Returns the maximum path sum of any non-empty path in a binary tree.
 * A path is defined as any sequence of nodes connected by edges, and does not need to pass through the root.
 * The path sum is the sum of the node values along the path.
 *
 * @param root The root node of the binary tree.
 * @return The maximum path sum found in the tree.
 */

#include "../TreeNode.h"
int ans = 0;
int maxPathDown(TreeNode *root)
{
  if (root == nullptr)
    return 0;
  int ls = max(0, maxPathDown(root->left));
  int rs = max(0, maxPathDown(root->right));
  ans = max(ans, ls + rs + root->val);
  return (root->val + max(ls, rs));
}

int maxPathSum(TreeNode *root)
{
  maxPathDown(root);
  return ans;
}