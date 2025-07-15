#include <iostream>
using namespace std;

// Define the Node structure
class Node {
public:
    int data;        // Value stored in the node
    Node* next;      // Pointer to the next node

    // Constructor to easily create a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at the end of the linked list
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);  // Create a new node

    if (head == nullptr) {
        // If the list is empty, new node becomes the head
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = newNode;
}

// Function to search for an element in the linked list
bool searchElement(Node* head, int key) {
    Node* current = head;  // Start from the head of the list

    // Traverse the list node by node
    while (current != nullptr) {
        if (current->data == key) {
            // If the value matches the key, return true
            return true;
        }
        current = current->next;  // Move to the next node
    }

    // If we reach here, key was not found
    return false;
}

// Function to print the linked list (for verification)
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// Main function to test the search
int main() {
    Node* head = nullptr;  // Initialize an empty linked list

    // Insert some elements
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    // Print the list
    cout << "Linked List: ";
    printList(head);

    // Element to search for
    int key;
    cout << "Enter value to search in the list: ";
    cin >> key;

    // Perform the search
    if (searchElement(head, key)) {
        cout << key << " is present in the linked list." << endl;
    } else {
        cout << key << " is NOT present in the linked list." << endl;
    }

    return 0;
}
