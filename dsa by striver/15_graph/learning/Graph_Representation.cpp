#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int adj[n + 1][m + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  return 0;
}

// using array of vector to store the graph.

int main()
{
  int n, m;
  cin >> n, m;
  vector<int> arr[n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u, v;
    // if undirected graph;
    arr[u].push_back(v);
    arr[v].push_back(u); // we will comment this line if graph was directed ie u --> v only.
  }
  return 0;
}

// now if the graph is weighted

int main()
{
  int n, m;
  vector<pair<int, int>> arr[n + 1];

  return 0;
}