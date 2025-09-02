#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

void postorder (Node* root) {
  if (root == nullptr) return;

  postorder(root->right);
  postorder(root->left);
  cout << root->data;

}