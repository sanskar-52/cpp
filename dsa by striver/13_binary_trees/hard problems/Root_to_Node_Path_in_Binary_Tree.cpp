// either node or node's value will be given and you have to find the path from root to node

#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// TC -> O(N)

// SC =  O(h) where h is the height of the tree
// → Worst case: O(n), Best case: O(log n)
class Solution
{
public:
  bool getPath(TreeNode *root, int val, vector<int> &ans)
  {
    if (root == nullptr)
      return false;

    ans.push_back(root->val);
    if (root->val == val)
      return true;

    if (getPath(root->left, val, ans))
    {
      return true;
    }

    if (getPath(root->right, val, ans))
    {
      return true;
    }

    ans.pop_back();
    return false;
  }
};