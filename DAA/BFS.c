#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//node
struct Node
{
  int vertex;
  struct Node* next; 
};

// adj list
struct Node* adj[100];

//creating a node
struct Node* createNode(int v) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// add edge
void addEdge(int u, int v) {
  struct Node* node = createNode(v);
  node->next = adj[u];
  adj[u] = node;

  node = createNode(u);
  node->next = adj[v];
  adj[v] = node;
}

void BFS(int start, bool visited[], int ans[], int* count) {
  

  int queue[100];
  int front = 0, rear = 0;

  visited[start] = true;
  queue[rear++] = start;

  while(front < rear) {
    int current = queue[front++];
    ans[(*count)++] = current;

    struct Node* temp = adj[current];
    while(temp != NULL) {
      int v = temp->vertex;

      if(!visited[v]) {
        visited[v] = true;
        queue[rear++] = v;
      }

      temp = temp->next;
    }
  }

}

int main() {
  int V = 6;

  for(int i = 0; i < V; i++) {
    adj[i] = NULL;
  }

  addEdge(1,2);
  addEdge(0,3);
  addEdge(2,0);
  addEdge(5,4);

  int ans[100];
  int count = 0;
  bool visited[100] = {false};
  printf("BFS starting from 0 \n");
  for(int i = 0; i < V; i++) {
    if(!visited[i]) {
      BFS(i,visited,ans,&count);
    }
  }

  for(int i = 0; i < count; i++) {
    printf("%d ", ans[i]);
  }
  
  return 0;
}