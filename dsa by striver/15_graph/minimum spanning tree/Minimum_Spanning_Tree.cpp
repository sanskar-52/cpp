/**
 * @brief Finds the minimum spanning tree (MST) of a weighted, undirected graph.
 *
 * A minimum spanning tree is a subset of edges that connects all vertices in the graph
 * with the minimum possible total edge weight, without forming any cycles.
 *
 * @details
 * This implementation uses either Kruskal's or Prim's algorithm to compute the MST:
 * - Kruskal's Algorithm: Sorts edges by weight and greedily adds edges that don't
 *   create cycles (uses Union-Find data structure).
 * - Prim's Algorithm: Starts from a vertex and repeatedly adds the minimum weight edge
 *   that connects to an unvisited vertex.
 *
 * @param graph The input weighted undirected graph represented as an adjacency list
 *              or edge list.
 * @param vertices The number of vertices in the graph.
 * @param edges The collection of edges with their weights.
 *
 * @return A vector/set of edges that form the minimum spanning tree.
 *
 * @time_complexity O(E log E) for Kruskal's or O((V + E) log V) for Prim's with a heap.
 * @space_complexity O(V + E) for storing the graph and result.
 *
 * @note The graph must be connected for a spanning tree to exist.
 *       If the graph is disconnected, a minimum spanning forest is returned.
 *
 * @see Union-Find (Disjoint Set Union) data structure for cycle detection.
 * @see Priority Queue for efficient edge selection in Prim's algorithm.
 */