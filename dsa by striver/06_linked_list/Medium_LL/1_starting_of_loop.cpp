//if we want to find starting point of loop
// we can do this by remembering if we visited a node earlier or not
// by unordered map ie hashing

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
  Node* temp = head;
  std::unordered_map<Node*, int> nodeMap;

  while(temp != nullptr){
    if(nodeMap.find(temp) != nodeMap.end()){
      return temp;
    }
    nodeMap[temp] = 1;
    // nodeMap.insert({temp,1});
    temp = temp->next;
  }

  return nullptr; //no loop
};

int main(){


  return 0;
}