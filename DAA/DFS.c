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

  node = createNode(u);
  node->next = adj[v];
  adj[v] = node;
}

// DFS
void DFS(int node, bool visited[], int ans[], int* count) {
  visited[node] = true;
  ans[(*count)++] = node;

  struct Node* temp = adj[node];
  while(temp != NULL) {
    int v = temp->vertex;

    if(!visited[v]) {
      DFS(v, visited, ans, count);
    }
    temp = temp->next;
  }
}


int main() {
  int V = 6;
  for(int i = 0; i< V; i++) {
    adj[i] = NULL;
  }

  addEdge(1,2);
  addEdge(0,3);
  addEdge(2,0);
  addEdge(5,4);
  bool visited[100] = {false};
  int count = 0;
  int ans[100];

  for(int i = 0; i < V; i++) {
    if(!visited[i]){
      DFS(i, visited, ans, &count);
    }
  }

  for(int i = 0; i < count; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}