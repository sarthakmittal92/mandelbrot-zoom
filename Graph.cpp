#include "Graph.h"
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

// constructor
Graph::Graph (long long int vertices, long long int edges) {

  n = vertices;
  m = edges;
  adj = new vector<long long int> [n];

}

// ---------------------------------------- FUNCTIONS --------------------------------------

// adding edges
void Graph::addEdge (long long int u, long long int v) {

  if (find(adj -> begin(),adj -> end(),u) != adj -> end()) {
    adj[u].push_back(v);
  }

}

// traversal
void Graph::bfsdfs (long long int s, bool choice) {

  bool visited[n];
  for (long long int i = 0; i < n; i++) {
    visited[i] = false;
  }

  deque<long long int> q;

  // choosing traversal
  if (choice == false) {
    q.push_back(s);
  }
  else {
    q.push_front(s);
  }

  visited[s] = true;
  while (!q.empty()) {

    long long int u = q.front();
    cout << u << " ";
    q.pop_front();

    for (long unsigned int i = 0; i < adj[u].size(); i++) {

      if (!visited[adj[u][i]]) {

        if (choice == false) {
          // bfs adds at end
          q.push_back(adj[u][i]);
        }
        else {
          // dfs adds at start
          q.push_front(adj[u][i]);
        }
        visited[adj[u][i]] = true;

      }

    }
  }
  cout << endl;

}

// bipartite check
bool Graph::isBipartite (long long int v, bool visited[], bool color[]) {

  for (long long int u : adj[v]) {

    if (!visited[u]) {
      visited[u] = true;
      color[u] = !color[v];
      if (!isBipartite(u, visited, color)) {
        return false;
      }
    }
    else if (color[u] == color[v]) {
      return false;
    }

  }
  return true;

}