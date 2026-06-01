#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];
 

bool dfs(int vertex , int par) {
  // Take action on vertex after entering the vertex


  vis[vertex] = true; 

  bool isloop = false;

  for (int child : g[vertex]) { 

    if (vis[child] && child == par) continue;
    if (vis[child]) return true;

    // Take action on child before entering the child node


    isloop = isloop || dfs(child, vertex);

    // Take action on child after exiting child node


  }
  // Take action on vertex before exiting the vertex

  return isloop;
}

int main() {

  int n=8;

  vector<vector< int>> edges = {
    {1, 2},
    {2, 3},
    {2, 4},
    {3, 5 },
    {6, 7},
    {1,5} // remove no loop
  };

 
  for (int i = 0; i < edges.size(); ++i) {
    int v1 = edges[i][0], v2 = edges[i][1]; 
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }

  bool isloop = false;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
     
    if(dfs(i,0)) {
      isloop = true;
      break;
    }
     
  }
   
  cout << isloop ? "Graph contains a loop" : "Graph does not contain a loop"; 

}
