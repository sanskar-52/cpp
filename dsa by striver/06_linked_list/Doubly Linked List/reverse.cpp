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