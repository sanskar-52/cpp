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

Node* removeNth(Node* head,int N){
  //N is nth node from the back to delete
  //we will iterate to node before it

  //we have to get the length of nodes
  Node* temp = head;
  int cnt = 0;
  while(temp != nullptr){
    temp = temp->next;
    cnt++;
  }
  //we got the length of nodes
  if(N == cnt){
    Node* newHead = head->next;
    delete head;
    return newHead;
  }
  //now we will iterate the node before the node which will be deleted
  temp = head;
  for(int i = 1; i < cnt-N; i++){
    temp = temp->next;
  }
  Node* delNode = temp->next;
  temp->next = temp->next->next;
  delete delNode;
  return head;
}

