#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;

  vector<vector<int>> adj(n+1);
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;

    adj[x].push_back(y);
    adj[y].push_back(x);

  }
  vector<int> visited(n+1,0);
  vector<int> level(n+1,0);
  vector<int> parent(n+1, -1);

  queue<int> q;
  q.push(1);
  visited[1]=1;
  level[1] =1;

  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(int neigh : adj[node]){
      if(!visited[neigh]) {
        q.push(neigh);
        visited[neigh]=1;
        level[neigh] = level[node]+1;

        parent[neigh] = node;

      }
    }
  }

  if(visited[n]==1) {
    cout<<level[n]<<endl;

    vector<int> path;
    for(int cur = n; cur != -1; cur = parent[cur]){
      path.push_back(cur);
    }

    reverse(path.begin(), path.end());

    for(int node : path){
      cout << node << " ";
    }
    cout << endl;
  }
  else cout<<"IMPOSSIBLE"<<endl;
  
  


}