#include <stdio.h>
#include <stdlib.h>

// ------------------------
// Node Structure
// ------------------------
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Constructor-like function for C
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ------------------------
// Stack Implementation
// ------------------------
struct Stack {
    struct Node* arr[1000];   // adjust size if needed
    int top;
};

void initStack(struct Stack* st) {
    st->top = -1;
}

int isEmpty(struct Stack* st) {
    return st->top == -1;
}

void push(struct Stack* st, struct Node* x) {
    st->arr[++(st->top)] = x;
}

struct Node* pop(struct Stack* st) {
    return st->arr[(st->top)--];
}

// ------------------------
// Iterative Preorder Traversal
// ------------------------
void preOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack st;
    initStack(&st);

    push(&st, root);

    while (!isEmpty(&st)) {
        struct Node* uparWaala = pop(&st);
        printf("%d ", uparWaala->data);

        // Push RIGHT first so LEFT comes out first
        if (uparWaala->right != NULL)
            push(&st, uparWaala->right);

        if (uparWaala->left != NULL)
            push(&st, uparWaala->left);
    }
}

// ------------------------
// Example Usage
// ------------------------
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder Traversal: ");
    preOrderTraversal(root);

    return 0;
}
