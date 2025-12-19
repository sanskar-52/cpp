// prim's algo
// Given a weighted, undirected and connected graph of V vertices and E edges.
// The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

#include <bits/stdc++.h>
using namespace std;

/**
 * Implementation notes for Prim's Algorithm to compute the weight sum of a Minimum Spanning Tree (MST).
 *
 * Class: Solution
 * Method: spanningTree(int V, vector<vector<int>> adj[])
 *
 * Parameters:
 * - V: number of vertices in the graph (assumed 0-indexed nodes [0 .. V-1]).
 * - adj: adjacency list where adj[u] is a vector of neighbors of u and each neighbor
 *        is represented as a vector<int> of size 2: {adjNode, edgeWeight}.
 *
 * Return:
 * - Returns the total weight (int) of the Minimum Spanning Tree formed by the graph.
 *
 * High-level approach (Prim's algorithm using a min-heap):
 * 1. Use a min-priority queue (min-heap) to always pick the next smallest-weight edge
 *    that connects a visited node to an unvisited node. The heap stores pairs {weight, node}.
 *
 * 2. Maintain a visited array `vis` of size V to mark which vertices are already included
 *    in the MST. Initially all vertices are unvisited.
 *
 * 3. Start the MST from an arbitrary node (here node 0):
 *    - Push {0, 0} into the min-heap to seed the process (cost of including start node is 0).
 *    - Initialize `sum = 0` to accumulate the weights of the edges chosen for the MST.
 *
 * 4. While the priority queue is not empty:
 *    a. Pop the top element of the heap to get the candidate {wt, node} with smallest wt.
 *    b. If `node` is already visited, skip it (this avoids cycles and duplicate edges).
 *    c. Otherwise:
 *       - Mark `node` as visited (include it into the MST).
 *       - Add `wt` to `sum` (this is the weight of the edge that connected `node` to MST; for start node wt=0).
 *    d. Explore all adjacency entries for `node`. For each neighbor entry:
 *       - Extract `adjNode = it[0]` and `edgeWeight = it[1]`.
 *       - If `adjNode` is not visited, push {edgeWeight, adjNode} into the min-heap as a candidate edge.
 *
 * 5. When the heap is exhausted, all reachable vertices have been processed and `sum` holds the total MST weight.
 *
 * Complexity:
 * - Time: O(E log V) where E is the number of edges (each edge can be pushed into heap once and heap ops cost log V).
 * - Space: O(V + E) for the visited array and heap entries (and the adjacency representation).
 *
 * Notes / assumptions:
 * - The code assumes the input graph is connected (common in MST problems). If the graph is disconnected,
 *   this will compute the MST weight of the component containing the start node (node 0) only.
 * - Adjacency entries must be exactly of the form {adjNode, edgeWeight}.
 * - Uses 0-based vertex indexing; adjust the start seed if another indexing is required.
 */
class Solution
{
public:
  // Function to find sum of weights of the Minimum Spanning tree
  // in vector<vector<int>>  -> {{adjNode, edW}, {adjNode, edW}, {adjNode, edW}, ... }
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(V, 0);
    // {wt, node}
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
      int wt = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      if (vis[node])
      {
        continue;
      }
      vis[node] = 1;
      sum += wt;
      for (auto it : adj[node])
      {
        int adjNode = it[0];
        int edW = it[1];
        if (!vis[adjNode])
        {
          pq.push({edW, adjNode});
        }
      }
    }
    return sum;
  }
};