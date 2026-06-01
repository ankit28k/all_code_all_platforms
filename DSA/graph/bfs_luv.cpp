#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];
int level[N];

void bfs(int source) {
  queue<int> q;
  q.push(source);
  vis[source] = 1;

  while (!q.empty()) {
    int cur_v = q.front();
    q.pop();

    cout << cur_v << " ";  // Print the current node

    for (int child : g[cur_v]) {
      if (!vis[child]) {
        q.push(child);
        vis[child] = 1;
        level[child] = level[cur_v] + 1;
      }
    }
  }
}
 
int main() {
    int n = 13; // Number of nodes
    vector<vector< int>> edges = {
      {1, 2},
      {1, 3},
      {1, 13},
      {2, 5},
      {5, 6},
      {5, 7},
      {5, 8},
      {8, 12},
      {3, 4},
      {4, 9},
      {4, 10},
      {10, 11},
      {9, 11}
    };

    // Build the adjacency list
    for (int i=1;i< edges.size() ;i++) {
        
      int v1 = edges[i][0] , v2 = edges[i][1];
      g[v1].push_back(v2);
      g[v2].push_back(v1); // Since the graph is undirected

    }
 
    bfs(1);
    for(int i=1;i<=n ;i++){
      cout << "Level of node " << i << " is " << level[i] << endl ;
    }

    return 0;
}
 