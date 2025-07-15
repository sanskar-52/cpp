/// @brief Reverses the data values of a singly linked list using a stack.
///        The actual node connections (pointers) are not changed; only the values are reversed.
/// @param head Pointer to the head of the linked list.
/// @return The same head pointer, with node data reversed.

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
  stack<int> st;          // Stack to store the data values of nodes
  Node* temp = head;      // Temporary pointer to traverse the list
  
  // Step 1: Traverse the list and push all data values onto the stack
  while (temp != nullptr) {
    st.push(temp->data);  // Save current node's data
    temp = temp->next;
  }
  
  // Step 2: Traverse the list again and replace each node's data with top of the stack
  temp = head;
  while (temp != nullptr) {
    temp->data = st.top();  // Get the last stored value
    st.pop();               // Remove that value from the stack
    temp = temp->next;
  }
  
  // The node order is unchanged, only the values are reversed
  return head;
}
