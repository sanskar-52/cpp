#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1 = nullptr, Node*prev1 = nullptr){
        data = data1;
        next = next1;
        prev = prev1;
    }
};

pair<Node*, Node*> arr2DLL(vector<int> &arr){
    if(arr.empty()) return {nullptr,nullptr};

    Node* head = new Node(arr[0]);
    Node* walker = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,walker);
        walker->next = temp;
        walker = temp;
    }

    return {head,walker};
}

void PrintForward(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertionBeginning(int data,Node* head){
    Node* temp = new Node(data,head,nullptr);
    if(head != nullptr){
    head->prev = temp;
    }
    return temp;
}

Node* insertionEnd(int data,Node* tail){
    Node* temp = new Node(data,nullptr,tail);
    if(tail != nullptr){
    tail->next = temp;
    }
    return temp;
}

void InsertionAtK(int data,Node*& head, int k){

    if(k<=0){
        cout << "invalid position" << endl;
        return;
    }

    if(k == 1){
        Node* temp = new Node(data, head, nullptr);
        if(head != nullptr){
            head->prev = temp;
        }
        head = temp;
        return;
    }


    Node* walker = head;
    for(int i = 1; i < k -1 && walker != nullptr; i++){
        walker = walker->next;
    }

    if(walker == nullptr){
        cout << "position out of bounds" << endl;
        return;
    }

    // Case 2: Insertion in the middle or end
    Node* temp = new Node(data,walker->next,walker);
    walker->next = temp;
    if(walker->next != nullptr){
        walker->next->prev = temp;
    }
}

int main(){
    vector<int> arr = {12,2,4,7};
    //now i have to make a Doubly linked list of this array.
    auto[head, tail] = arr2DLL(arr);

    // 1. Insertion Operations in DLL

    // Beginning
    head = insertionBeginning(63,head);
    PrintForward(head);
    
    // End
    tail = insertionEnd(57,tail);
    PrintForward(head);
    
    // Kth position (in the middle)
    int k = 9;
    InsertionAtK(3,head,k);
    PrintForward(head);

    return 0;
}