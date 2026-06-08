#include <stdio.h>
#include <stdlib.h>
// structure of node
struct Node {
  int vertex;
  struct Node* next;
};

// initallizing adj list
struct Node* adj[100];

// createNode function
struct Node* createNode(int v) {
  struct Node* newNode = (struct Node*)malloc((sizeof(struct Node)));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// adding Edges
void addEdge(int u, int v) {
  struct Node* node = createNode(v);
  node->next = adj[u];
  adj[u]= node;
}

// kahn's algo
void topologicalSort(int V) {
  int inDegree[100] = {0};
  
  // counting inDegree of every vertex
  for(int i = 0; i < V; i++) {
    struct Node* temp = adj[i];
    while(temp != NULL) {
      int v = temp->vertex;
      inDegree[v]++;
      temp = temp->next;
    }
  }

  // queue
  int queue[100];
  int front = 0, rear = 0;

  for(int i = 0; i < V; i++) {
    if(!inDegree[i]) {
      queue[rear++] = i;
    }
  }

  // process queue
  while(front < rear) {
    int current = queue[front++];
    printf("%d ", current);

    struct Node* temp = adj[current];
    while(temp != NULL) {
      int v = temp->vertex;
      inDegree[v]--;
      
      if(inDegree[v] == 0) {
        queue[rear++] = v;
      }

      temp = temp->next;
    }
  }

}


int main() {
  int V = 6;
  // initiallizing adj list to NULL.
  for(int i = 0; i < V; i++) {
    adj[i] = NULL;
  }

  addEdge(5, 2);
  addEdge(5, 0);
  addEdge(4, 0);
  addEdge(4, 1);
  addEdge(2, 3);
  addEdge(3, 1);

  topologicalSort(V);

  return 0;
}