//delete the middle node
//for even sized linked lists we will delete the 2nd middle node
//and return the head

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

//first we will need to find the middle of the linked list
//for that we can use size of linked list or slow and fast pointer

//in slow and pointer method the slow pointer end up on the middle node
//but we want to end up a node before the middle node
//so we will skip slow = slow->next one time so it lags one node


Node* deleteMiddle(Node* head){
  if(head == nullptr || head->next == nullptr){return nullptr;}

  Node* slow = head; //now slow lags one step always
  Node* fast = head->next->next; 

  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }

  Node* middle = slow->next;
  slow->next = slow->next->next;
  delete middle;

  return head;
}

void printLL(Node* head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main(){
  //creating linked list
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  cout << "origianl linked list" << endl;
  printLL(head);

  head = deleteMiddle(head);

  cout << "modified linked list" << endl;
  printLL(head);


  return 0;
}