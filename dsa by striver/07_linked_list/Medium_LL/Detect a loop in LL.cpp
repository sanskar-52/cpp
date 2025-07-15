//so in 1D LL all we can do is move forward so how can we detect a loop
//we have to remember if we have visited a node before or not
//we will store the entire node in the hash and the count
//so we will use Hashing to keep track
//few things to keep in mind
//in loop there is never a last node. . .

//TortoiseHare method
// TC -> O(N)  AND   SC -> O(1)
#include<iostream>
#include<vector>
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
  Node* mover = head;
  for(int i = 1; i < arr.size(); i++ ){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

bool hasLoop(Node* head){
  Node* slow = head;
  Node* fast = head;

  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      return true;
    }
  }
  return false;
}

int main(){
  return 0;
}

//how do i create a loop though?