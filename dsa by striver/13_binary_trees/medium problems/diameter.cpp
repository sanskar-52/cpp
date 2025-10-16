// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

// so how can we find the length of the longest path between any two nodes in a tree?
// 🧠  @attention   Intuition:
//
// The longest path in a tree can be formed in two ways:
//
// 1️⃣ It passes through the current root → path = left_height + right_height
// 2️⃣ It lies entirely in the left or right subtree
//
// So, for every node, we compute:
//   - left_height
//   - right_height
//   - possible_diameter = left_height + right_height
// The maximum of these across all nodes gives the final diameter.

#include "../TreeNode.h"

int diameter = 0;
int height(TreeNode *root)
{
  if (root == nullptr)
    return 0;
  int lh = height(root->left);
  int rh = height(root->right);

  diameter = max(diameter, lh + rh);

  return 1 + max(lh, rh);
}
/**
 * Calculates the height of a binary tree rooted at the given node.
 * Also updates the global variable 'diameter' to store the maximum diameter found so far.
 *
 *
 * Time Complexity: O(N), where N is the number of nodes in the tree.
 *   - Each node is visited once.
 *
 * Space Complexity: O(H), where H is the height of the tree.
 *   - Due to recursion stack space.
 *
 * @param root Pointer to the root node of the binary tree.
 * @return The height of the tree rooted at 'root'.
 */
