// Problem Statement: Given an undirected graph, return a vector of all nodes by traversing the graph using breadth-first search (BFS).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Performs a Breadth-First Search (BFS) traversal on an undirected graph
 *
 * @param V The number of vertices in the graph (0 to V-1)
 * @param adj[] An array of vectors representing the adjacency list of the graph,
 *              where adj[i] contains all vertices adjacent to vertex i
 *
 * @return A vector<int> containing the vertices in BFS order starting from vertex 0
 *
 * @details
 * - Starts BFS from vertex 0
 * - Uses a visited array to track visited vertices and avoid cycles
 * - Employs a queue data structure for level-order traversal
 * - Time Complexity: O(V + E) where V is vertices and E is edges
 * - Space Complexity: O(V) for the visited array and queue
 *
 * @note This implementation assumes:
 *       - Vertices are numbered from 0 to V-1
 *       - The graph is connected or BFS explores only the component containing vertex 0
 *       - The graph is represented using an adjacency list
 */
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
  int vis[V] = {0};
  vis[0] = 1;
  queue<int> q;
  q.push(0);
  vector<int> bfs;

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    bfs.push_back(node);

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        vis[it] = 1;
        q.push(it);
      }
    }
  }

  return bfs;
}