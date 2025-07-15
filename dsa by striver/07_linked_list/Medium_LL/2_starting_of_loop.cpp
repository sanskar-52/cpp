//we will find starting point of loop by tortoise and hare method
//first we will reach the intersection of slow and fast pointer
//then assign slow = head then move them forward until they are at same node again
//that node is the starting point of the loop

//optimal solution tortoise and hare method
// SC -> O(1)

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

Node* startingLoop(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      cout << "there is a loop in this Linked List" << endl;
      slow = head;
      while (slow != fast)
      {
        slow = slow->next;
        fast = fast->next;
      }
      return fast;
    }
  }
  return nullptr;
}