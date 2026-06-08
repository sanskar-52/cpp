#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

class Solution
{
public:
  int floorBST(TreeNode *root, int key)
  {
    int floor = -1;
    while (root)
    {
      if (root->val > key)
      {
        root = root->left;
      }

      else
      {
        floor = root->val;
        root = root->right;
      }
    }

    return floor;
  }
};