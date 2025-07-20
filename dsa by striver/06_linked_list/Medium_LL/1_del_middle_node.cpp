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
//in this code we will be using the size of linked list to find the middle.

Node* deleteMiddle(Node* head){
  if(head == nullptr || head->next == nullptr) {return nullptr;}
  int n = 0;
  Node* temp = head;
  while(temp != nullptr){
    n++;
    temp = temp->next;
  }
  temp = head;

  int res = n/2;

  while(temp != nullptr){
    res--;

    if(res == 0){
      Node* middle = temp->next;
      temp->next = temp->next->next;
      delete middle;

      break;
    }

    temp = temp->next;
  }

  return head;

}

void printLL(Node* head){
  Node* temp = head;
  while(temp != nullptr){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main(){
  //creating linked list
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  // head->next->next->next->next = new Node(5);

  cout << "origianl linked list" << endl;
  printLL(head);

  head = deleteMiddle(head);

  cout << "modified linked list" << endl;
  printLL(head);


  return 0;
}