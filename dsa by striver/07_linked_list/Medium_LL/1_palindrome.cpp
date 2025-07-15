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

bool isPalindrome(Node* head){
  Node* temp = head;
  stack<int> st;
  while(temp != nullptr){
    st.push(temp->data);
    temp = temp->next;
  }

  temp = head;
  while(temp != nullptr){
    if(temp->data == st.top()){
      temp = temp->next;
      st.pop();
    }
    else{ return false; }
  }
  return true;
}