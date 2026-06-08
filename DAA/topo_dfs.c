#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// node
struct Node {
  int vertex;
  struct Node* next;
};

// adj list
struct Node* adj[100];

// create a node
struct Node* createNode(int v) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->next = NULL;
  newNode->vertex = v;
  return newNode;
}

// addEdge
void addEdge(int u, int v) {
  struct Node* node = createNode(v);
  node->next = adj[u];
  adj[u] = node;
}

// DFS

void DFS(int node, bool visited[], int stack[], int* top) {
  visited[node] = true;

  struct Node* temp = adj[node];
  while(temp != NULL) {
    int v = temp->vertex;
    if(!visited[v]){
      DFS(v, visited, stack, top);
    }
    temp = temp->next;
  }
  stack[(*top)++] = node;
}

int main() {
  int V = 6;
  // intializing adj list to NULL
  for(int i = 0; i< V; i++) {
    adj[i] = NULL;
  }
  // adding edges u -> v
  addEdge(5, 2);
  addEdge(5, 0);
  addEdge(4, 0);
  addEdge(4, 1);
  addEdge(2, 3);
  addEdge(3, 1);
  // initalizing visited array
  bool visited[100] = {false};
  // declaring stack and top
  int stack[100];
  int top = 0;


  for(int i = 0; i < V; i++) {
    if(!visited[i])
    DFS(i, visited, stack, &top);
  }

  for(int i = top - 1; i >= 0; i--) {
    printf("%d ",stack[i]);
  }

  return 0;
}