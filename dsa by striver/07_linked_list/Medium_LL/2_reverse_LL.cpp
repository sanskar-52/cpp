/// @brief Reverses a singly linked list in-place by changing the direction of the node pointers.
/// @param head Pointer to the head of the original linked list.
/// @return Pointer to the new head of the reversed linked list.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;            
  Node* next;      
  Node(int data1, Node* next1) {
    data = data1;
    next = next1;
  }
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

Node* reverse(Node* head) {
  Node* temp = head;       // Current node we're processing
  Node* prev = nullptr;    // Previous node (initially null for the new tail)
  Node* front;             // Used to temporarily store the next node
  
  // Iterate through the list
  while (temp != nullptr) {
    front = temp->next;     // Save next node before breaking the link
    temp->next = prev;      // Reverse the current node's pointer
    prev = temp;            // Move 'prev' one step forward
    temp = front;           // Move to the next node
  }
  
  // After the loop, 'prev' points to the new head of the reversed list
  return prev;
}
