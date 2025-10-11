#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node* left; // in c you have to write struct before declaring a node pointer.
  struct Node* right;// in cpp it's not compulsory.

  Node(int value) {
    data = value;
    left = right = nullptr;
  }
};

void pre_order (Node* root) {
  if (root == nullptr) return;

  cout << root->data;
  
  pre_order(root->left);
  pre_order(root->right);
}

// Time Complexity: O(n)
  //   - Each node in the binary tree is visited exactly once.
  //   - 'n' is the total number of nodes in the tree.


// Space Complexity: O(h)
  //   - 'h' is the height of the tree.
  //   - Space is used by the recursion stack.
  //   - In the worst case (skewed tree), h = n; in the best case (balanced tree), h = log n.