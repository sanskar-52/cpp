//we will store the data of LL in array
//and then sort the array and we will put back sorted data into LInked List

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

void merge(vector<int> &arr, int left, int mid, int right){
  vector<int> temp;
  int i = left;
  int j = mid+1;

  while(i <= mid && j <= right){
    if(arr[i] < arr[j]){
      temp.push_back(arr[i]);
      i++;
    }
    else {
      temp.push_back(arr[j]);
      j++;
    }
  }

  while(i <= mid) {
    temp.push_back(arr[i]);
    i++;
  }

  while(j <= right){
    temp.push_back(arr[j]);
    j++;
  }

  for(int i = left; i <= right; i++){
    arr[i] = temp [i - left];
  }
}

void merge_sort(vector<int> &arr, int left, int right){
  if(left >= right) return;
  int mid = (left + right)/2;
  merge_sort(arr, left, mid);
  merge_sort(arr, mid+1, right);
  merge(arr, left, mid, right);

}

Node* sortLL(Node* head){
  vector<int> arr;
  Node* temp = head;
  while(temp != nullptr){
    arr.push_back(temp->data);
    temp = temp->next;
  }//vector ban gaya with all the data of LL

  // now we will sort it using merge sort
  merge_sort(arr, 0 , arr.size() - 1);
  //array is sorted.🤓☝️🧏

  temp = head;
  for(int i = 0; i < arr.size(); i++){
    temp->data = arr[i];
    temp = temp->next;
  }
  //sorted element wapas se daal diye linked list me
  return head;

}

void printLinkedList(Node* head) {
Node* temp = head;
while (temp != nullptr) {
  // Print the data of the current node
    cout << temp->data << " "; 
    // Move to the next node
    temp = temp->next; 
  }
  cout << endl;
}
