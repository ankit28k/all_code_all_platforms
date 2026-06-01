#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];

void dijkstra(int source, int n) {
  
  vector<int> dist(n + 1, INF);
  vector<bool> visited(n + 1, false);
  set<pair<int, int>> st;

  dist[source] = 0;
  st.insert({0, source});

  while (st.size()>0) {
    auto  node = *st.begin();
    int vertex = node.second;
    int distance = node.first;

    st.erase(st.begin());
    
    if(visited[vertex]) continue;
    visited[vertex] = true;

    for (auto child : g[vertex]) {
      int child_v = child.first;
      int wt = child.second;

      if (dist[vertex] + wt < dist[child_v]) {
        dist[child_v] = dist[vertex] + wt;
        st.insert({dist[child_v], child_v});
      }
    }
  }
}

void dijkstraPriorityQueue(int source, int n) {
  vector<int> dist(n + 1, INF);
  vector<bool> visited(n + 1, false);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  dist[source] = 0;
  pq.push({0, source});

  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();

    if (visited[v]) continue;
    visited[v] = true;

    for (auto child : g[v]) {
      int child_v = child.first;
      int wt = child.second;

      if (dist[v] + wt < dist[child_v]) {
        dist[child_v] = dist[v] + wt;
        pq.push({dist[child_v], child_v});
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++ ) {
    int x, y, wt;
    cin >> x >> y >> wt;
    g[x].push_back({y, wt});
  }

  int source;
  cin >> source;
  dijkstra(source, n);

  return 0;
}
