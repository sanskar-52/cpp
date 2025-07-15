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

Node* del_k(Node *head,int k){
    int cnt=0;
    Node* counter = head;
    while(counter != nullptr){
        cnt++;
        counter = counter->next;
    }
    if(k==1){
        Node* temp= head;
        head = head->next;
        delete temp;
        return head;
    }
    else if(k==cnt){
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }
    else{
        Node* walker = head;
        for(int i = 1; i < k - 1; i++){
            walker = walker->next;
        }
        Node* temp = walker->next;
        walker->next = temp->next;
        delete temp;
        return head;
    }
}

int main(){



    return 0;
}
