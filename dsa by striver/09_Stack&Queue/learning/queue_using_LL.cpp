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


class Queue {
private:
  Node* start;
  Node* end;
  int size;


public:
  Queue(){
    size = 0;
    start = end = nullptr;
  }

  void push(int x){
    if(start == nullptr && end == nullptr){
      start = end = new Node(x);
    }
    else {
      Node* temp = new Node(x);
      end->next = temp;
      end = temp;
    }
    size++;
  }

  void pop(){
    if(start == nullptr && end == nullptr){
      cout << "the queue is empty" << endl;
      return;
    }
    
    Node* temp = start;
    start = start->next;
    if(start == nullptr){
      end = start;
    }
    delete temp;
    size--;
  }

  int top(){
    if(start == nullptr){
      cout << "the queue is empty\n";
      return -1;
    }

    return start->data;
  }

  int getSize(){
    return size;
  }

  bool isEmpty(){
    return start == nullptr;
  }

  ~Queue(){
    while(start != nullptr){
      pop();
    }

  }

};

int main() {
  Queue q;

  q.push(10);
  q.push(20);
  q.push(30);

  cout << "Front: " << q.top() << endl;
  cout << "Size: " << q.getSize() << endl;

  q.pop();
  cout << "Front after pop: " << q.top() << endl;

  while (!q.isEmpty()) {
    q.pop();
  }

  q.pop();  // Should show "the queue is empty"

  return 0;
}
