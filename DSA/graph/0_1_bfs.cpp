#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;

vector<pair<int, int>> graph[N]; // graph: node -> list of (child, weight)
vector<int> lev(N,-1); // level array for storing shortest distances

int bfs(){
  deque<int> q;
  q.push_back(1); // starting node
  lev[1] = 0;

  while (!q.empty()) {
    int cur_v = q.front();
    q.pop_front();

    for (auto child : graph[cur_v]) {
      int child_v = child.first;
      int wt = child.second;

      if (lev[cur_v] + wt < lev[child_v]) {
        lev[child_v] = lev[cur_v] + wt;

        if (wt == 1)  q.push_back(child_v);
        
        else q.push_front(child_v);
        
      }
    }
  }

  return lev[n] == -1 ? -1 : lev[n];

}

int main() {
    
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if(x==y) continue;
    graph[x].push_back({y, 0}); // edge with weight 0
    graph[y].push_back({x, 1}); // edge with weight 1
  }
  
  cout<<bfs()<<endl;
  return 0;
}
