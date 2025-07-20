//easy sol is to find the middle by (N/2 + 1) if there are even nodes
//6 nodes then return the node* which points to 4th node
//which we can do through (N/2 + 1)

//and now we by this method

// Middle of a LinkedList [TortoiseHare Method]
//slow and fast pointer

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int data1,Node* next1){
    data = data1;
    next = next1;
  }

  Node(int data1){
    data = data1;
    next = nullptr;
  }
};

Node* arr2LL(vector<int> &arr){
  Node* head = new Node(arr[0],nullptr);
  Node* temp = head;
  for(int i = 1 ; i < arr.size(); i++){
    temp->next = new Node(arr[i],nullptr);
    temp = temp->next;
  }
  return head;
}

Node* Middle(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}


int main(){

  vector<int> arr ={12,3,23,1,24};
  Node* head = arr2LL(arr);

  Node* middle = Middle(head);
  cout << "middle of arr is: " << middle->data;

  return 0;
}