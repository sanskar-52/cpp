//we will find len of loop using unordered map


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
  Node* temp = head;
  unordered_map<Node*, int> mpp;
  //this map will store node* and int
  int i = 1;
  while(temp != nullptr){
    //before inserting it, check if the node is already present or not;
    if(mpp.find(temp) !=  mpp.end()){
      return i - mpp[temp];
    }

    mpp.insert({temp,i});
    i++;
    temp = temp->next;
  }
  return 0;



}
