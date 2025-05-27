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
    Node* walker = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr);
        walker->next = temp;
        walker = temp;
    }
    return head;
}

Node* del_first(Node* head){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* del_last(Node* head){
    Node* temp = head;
    if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }

    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;


    return head;
}


int main(){
    vector<int> arr = {12,31,23,223,12,41,24};
    Node* head = arr2LL(arr);
    head = del_first(head);
    Node* temp = head;
    while(temp !=nullptr){
        cout << temp->data << ' ';
        temp = temp->next;
    }

    return 0;
}