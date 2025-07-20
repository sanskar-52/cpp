#include <iostream>
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
    //so this is how you create a node
    Node* head = new Node(12,nullptr);
// new Node(12, nullptr) creates a new Node object on the heap.
// It returns a pointer to that object, i.e., of type Node*.
// That pointer is stored in the variable head.
//this creates a head, similary we can create another node

    Node* second = new Node(13,nullptr);
    //now how we will connect these two nodes?
    //head node ka next pointer = second pointer
    head->next = second;
    //now the head and second node are connected.
    //ie next of head is pointing towards second node and the next of second is pointing towards null.
    // head -> [12 | *] -> [13 | null]
    return 0;
}