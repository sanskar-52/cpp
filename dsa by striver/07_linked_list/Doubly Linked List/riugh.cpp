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

pair<Node*, Node*> arr2DLL(vector<int> &arr){
    if(arr.empty()) return {nullptr,nullptr};

    Node* head = new Node(arr[0]);
    Node* walker = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, walker);
        walker->next = temp;
        walker = temp;
    }
    return { head , walker };   // walker is the tail
}

void PrintForward(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

void PrintBackward(Node* tail){
    Node* temp = tail;
    while(temp != nullptr){
        cout << temp->data << "  ";
        temp = temp->prev;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {12, 2, 4, 7, 13, 15, 17, 19, 21, 23, 27};
    
    auto [head, tail] = arr2DLL(arr);

    cout << "Forward traversal: ";
    PrintForward(head);

    cout << "Backward traversal: ";
    PrintBackward(tail);

    return 0;
}
