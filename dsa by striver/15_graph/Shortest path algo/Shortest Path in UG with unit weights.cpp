// Problem Statement: Given an Undirected Graph having unit weight, find the shortest path from the source to all other nodes in this graph. In this problem statement,
// we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
  {
    // edge pairs has been provided in form of vector of vecotor
    vector<int> adj[N];
    for (auto it : edges)
    {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    } // adjacency list created.

    int dist[N]; // array to store the distance of each node from the source.
    for (int i = 0; i < N; i++)
    {
      dist[i] = 1e9;
    } // intially setting every node's distance as very large.
    dist[src] = 0; // setting src distance from src to 0.

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      for (auto it : adj[node])
      {
        if (dist[it] > dist[node] + 1)
        {
          dist[it] = dist[node] + 1;
          q.push(it);
        }
      }
    }

    vector<int> ans(N);
    for (int i = 0; i < N; i++)
    {
      if (dist[i] == 1e9)
      {
        ans[i] = -1;
      }
      else
      {
        ans[i] = dist[i];
      }
    }

    return ans;
  }
};