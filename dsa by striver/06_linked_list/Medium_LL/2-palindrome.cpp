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

Node* reverse(Node* head){
  if(head == nullptr || head->next == nullptr){return head;}
  Node* newHead = reverse(head->next);
  Node* front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
}



bool isPalindrome(Node* head){
  Node* first = head;
  Node* fast = head;
  Node* slow = head;

  //finding the middle so we can reverse the 2nd half of the nodes
  while(fast->next != nullptr && fast->next->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }
  //slow is the middle Node pointer
  //for odd it is the middle
  //for even node it is the middle 1

  //now reverse the 2nd half of the Node
  Node* newHead = reverse(slow->next);
  Node* second = newHead;

  //iterating and comping 1st half and 2nd half
  while(second != nullptr){
    if(first->data != second->data) { return false; }
    else {
      first = first->next;
      second = second->next;
    }
  }

  //reversing it back to its original form
  reverse(newHead);
  //returing answer
  return true;

}