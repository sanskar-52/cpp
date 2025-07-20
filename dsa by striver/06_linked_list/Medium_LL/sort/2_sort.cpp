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

//uses turtoise and hare method to find middle for ll
//m1 for even sized LL
Node* findMiddle(Node* head){
  Node* slow = head;
  Node* fast = head->next;

  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;

}

//function to merge two sorted LL into 1 sorted LL

Node* merge(Node* leftHead, Node* rightHead){
  Node* dummyNode = new Node(-1);
  Node* temp = dummyNode;

  while(leftHead != nullptr && rightHead != nullptr){
    if(leftHead->data <= rightHead->data){
      temp->next = leftHead;
      leftHead = leftHead->next;
    }
    else {
      temp->next = rightHead;
      rightHead = rightHead->next;
    }
    temp = temp->next;
  }

  if(leftHead == nullptr){
    temp->next = rightHead;
  }
  else {
    temp->next = leftHead;
  }

  return dummyNode->next;
}

Node* merge_sort(Node* head){
  if(head == nullptr || head->next == nullptr) return head;
  Node* middle = findMiddle(head);
  Node* leftHead = head;
  Node* rightHead = middle->next;
  middle->next = nullptr;

  leftHead = merge_sort(leftHead);
  rightHead = merge_sort(rightHead);


  return merge(leftHead,rightHead);

}