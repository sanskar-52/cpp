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
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++ ){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int len_node(Node* head){
    Node* walker = head;
    int cnt = 0;
    while(walker != nullptr){
        cnt++;
        walker = walker->next;
    }
    return cnt;
}

int main(){
    vector<int> arr = {111,21,3,1231,2};
    Node* head = arr2LL(arr);
    // cout << head->data << '\n';

    Node* walker = head;
    while(walker != nullptr){
        cout << walker->data << ' ';
        walker = walker->next;
    }

    int length = len_node(head);
    cout << endl << "length of linked_list is " << length;
    return 0;
}