//basically imagine karo ki tum hath me stick lekar chal rhe ho ie stick.
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

//delete nth node from back
Node* removeNth(Node* head, int N){
  Node* stick = head;
  Node* temp = head;

  //stick ka length set kar rhe h
  while(N != 0){
    stick = stick->next;
    N--;
  }
  //Add head deletion check
  if(stick == nullptr){
    Node* newHead = head->next;
    delete head;
    return newHead;
  }

  //stick ke sath iterate kar rhe h
  while(stick->next != nullptr){
    stick = stick->next;
    temp = temp->next;
  }
  Node* delNode = temp->next;
  temp->next = temp->next->next;
  delete delNode;

  return head;
}