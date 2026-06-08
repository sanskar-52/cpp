#include <bits/stdc++.h>
#include "../TreeNode.h"
using namespace std;

// in this approach we are first making an vector path of both nodes
// then we iterate both vectors and last common node in the vectors is the LCA
class Solution
{
  // Time -> O(N) + O(N)  for finding path for both p and q
  // Spcae -> O(H) + O(H)  for auxillary space for vector pop and poq
public:
  bool pathOfNodeFromRoot(TreeNode *root, TreeNode *p, vector<TreeNode *> &path)
  {
    if (!root)
      return false;

    path.push_back(root);
    if (root->val == p->val)
      return true;

    if (pathOfNodeFromRoot(root->left, p, path))
      return true;
    if (pathOfNodeFromRoot(root->right, p, path))
      return true;

    path.pop_back();
    return false;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    vector<TreeNode *> pop;
    vector<TreeNode *> poq;

    if (!pathOfNodeFromRoot(root, p, pop))
      return nullptr;
    if (!pathOfNodeFromRoot(root, q, poq))
      return nullptr;

    int n = min(pop.size(), poq.size());
    TreeNode *last = nullptr;
    for (int i = 0; i < n; i++)
    {
      if (pop[i] == poq[i])
        last = pop[i];

      else
        break;
    }
    return last;
  }
};

// now the recursive solution

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == nullptr)
      return nullptr;

    if (root->val == p->val || root->val == q->val)
      return root;
    // left child and right child;
    TreeNode *lc = lowestCommonAncestor(root->left, p, q);
    if (lc && (lc->val != p->val && lc->val != q->val))
      return lc;
    TreeNode *rc = lowestCommonAncestor(root->right, p, q);

    if (lc && !rc)
      return lc;
    if (!lc && rc)
      return rc;
    if (lc && rc)
      return root;

    return nullptr;
  }
};