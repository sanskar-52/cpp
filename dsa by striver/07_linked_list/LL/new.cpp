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

int main(){
  vector<int> arr = {111,21,3,1231,2};
  vector<int> arr2 = arr;
  arr.pop_back();
  for(int x: arr){
    cout << x << " ";
  }
  for(int x: arr2){
    cout << x << " ";
  }
  int are[5] = {1,2,3,4,5};
  // int arr2[5] = are;
}
