#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev; 
    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr){
        data = data1;
        next = next1;
        prev = prev1;
    }
};
    
//trying on my own
/*
Node* arr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0],nullptr,nullptr);
    Node* walker = head;
    Node* backer = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,nullptr);
        walker->next = temp;
        walker = temp;
        walker->prev = backer;
        backer = temp;
    }
    return head;
}
*/


Node* arr2DLL(vector<int> &arr){
    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0],nullptr,nullptr);
    Node* walker = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,walker);
        walker->next = temp;
        walker = temp;
    }
    return head;
}

int main(){
    vector<int> arr = {12,2,4,7,13,15,17,19,21,23,27};
    //now i have to make a Doubly linked list of this array.

}