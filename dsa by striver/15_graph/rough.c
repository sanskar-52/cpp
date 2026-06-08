#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Node* adj[MAXV];

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

// DFS function
void dfs(int s, bool visited[], int component[], int* size) {
    visited[s] = true;
    component[(*size)++] = s;

    struct Node* temp = adj[s];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {
            dfs(v, visited, component, size);
        }
        temp = temp->next;
    }
}

// Get connected components
void getComponents(int V) {
    bool visited[MAXV] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            int component[MAXV];
            int size = 0;

            dfs(i, visited, component, &size);

            // Print component
            for (int j = 0; j < size; j++) {
                printf("%d ", component[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int V = 6;

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Add edges
    addEdge(1, 2);
    addEdge(0, 3);
    // addEdge(3, 5);
    addEdge(2, 0);
    addEdge(5, 4);

    // Find connected components
    getComponents(V);

    return 0;
}