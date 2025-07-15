/// @brief Recursively reverses a singly linked list by reversing the node pointers.
/// @param head Pointer to the head of the current (sub)list.
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
  // Base case: if the list is empty or has only one node, return it
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  
  // Step 1: Recursively reverse the rest of the list
  Node* newHead = reverse(head->next);  // This becomes the new head of the reversed list
  
  // Step 2: Reconnect the current node
  Node* front = head->next;  // Store the next node (now at the end after reversal)
  front->next = head;        // Make the next node point back to current node
  head->next = nullptr;      // Disconnect current node from the rest (to avoid cycle)
  
  // Step 3: Return the new head of the reversed list
  return newHead;
}
