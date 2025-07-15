// after the slow and fast intersect
// we will start a counter until they intersect again, that's it.

#include<iostream>
#include<bits/stdc++.h>
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

int lenOfLoop(Node* head){
  Node* slow = head;
  Node* fast = head;
  int counter = 1;
  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      fast = fast->next;
      while(fast != slow){
        fast = fast->next;
        counter++;
      }
      return counter;
    }
  }
  return 0;

}