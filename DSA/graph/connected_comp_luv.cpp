#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

vector<vector<int>> cc;
vector<int> current_cc; 

void dfs(int vertex) {
    // Take action on vertex after entering the vertex


    vis[vertex] = true;

    current_cc.push_back(vertex);

    for (int child : g[vertex]) { 

      if (vis[child]) continue;

      // Take action on child before entering the child node


      dfs(child);

      // Take action on child after exiting child node


    }
    // Take action on vertex before exiting the vertex


}

int main() {

  int n=8;

  vector<vector< int>> edges = {
    {1, 2},
    {2, 3},
    {4, 5},
    {5, 6},
    {6, 7}
  };

 
  for (int i = 0; i < edges.size(); ++i) {
    int v1 = edges[i][0], v2 = edges[i][1]; 
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }

  int ct = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    current_cc.clear();
    dfs(i);
    cc.push_back(current_cc);
    ct++;
  }
   
  cout<<"size:"<<cc.size()<<endl;

  for (auto c_cc : cc) {
    for (int vertex : c_cc) {
        cout << vertex << " ";
    }
    cout << endl;
  }

}
