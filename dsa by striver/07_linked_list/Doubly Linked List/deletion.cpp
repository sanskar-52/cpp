#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1,Node* next1 = nullptr,Node* prev1 = nullptr){
        data = data1;
        next = next1;
        prev = prev1;
    }
};

void DeletionAtK(Node*& head,int k){
    if( k<=0 || head == nullptr){
        cout << "invalid deletion" <<endl;
        return;
    }

    Node* temp = head;
    if(k==1){
        if(head->next != nullptr){
        head->next->prev = nullptr;
        }
        head = head->next;
        delete temp;
    }

    for(int i = 1; i < k && temp != nullptr; i++){
        temp = temp->next;
    }

    if(temp == nullptr){
        cout << "out of bounds" << endl;
        return;
    }

    if(temp->prev != nullptr){
        temp->prev->next = temp->next;
    }

    if(temp->next != nullptr){
        temp->next->prev = temp->prev;
    }
    delete temp;

}

int main(){


    return 0;
}