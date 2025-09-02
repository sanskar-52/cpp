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

int main() {
  struct Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  


}