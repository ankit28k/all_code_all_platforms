#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex) {
    // Take action on vertex after entering the vertex

    cout<<vertex<<endl;

    vis[vertex] = true;
    for (int child : g[vertex]) {

        cout<<"par:"<<vertex<<"child:"<<child<<endl;
        if (vis[child]) continue;

        // Take action on child before entering the child node


        dfs(child);

        // Take action on child after exiting child node


    }
    // Take action on vertex before exiting the vertex


}

int main() {

  vector<vector< int>> edges = {
    {1, 6},
    {2, 1},
    {3, 1},
    {4, 3},
    {5, 3},
    {6, 3},
    {7, 3},
    {8, 2},
    {9, 4},
    {10, 5}
  };

 
  for (int i = 0; i < edges.size(); ++i) {
      int v1 = edges[i][0], v2 = edges[i][1]; 
      g[v1].push_back(v2);
      g[v2].push_back(v1);
  }

     
    dfs(1); 
}
