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

class Stack{
private:
  Node* top;
  int size;

public:
  Stack(){
    top = nullptr;
    size = 0;
  }

  void push(int x){
    Node* temp = new Node(x);
    temp->next = top;
    top = temp;
    size++;
  }

  void pop(){
    if(top == nullptr){
      cout << "there is nothing to pop" << endl;
      return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
    size--;
  }

  int getSize(){
    return size;
  }

  int Top(){
    if(top == nullptr){
      cout << "stack is empty\n";
      return -1;
    }
    return top->data;
  }

  ~Stack() {
    while(top != nullptr){
      pop(); //frees all nodes
    }
  }

};