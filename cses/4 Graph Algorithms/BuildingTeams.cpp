#include<bits/stdc++.h>
using namespace std;
 
bool bfs(int source , vector<int> &visited,vector<vector<int>> &grid){
 
  queue<int> q;
  q.push(source);
  visited[source] = 0;

  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(auto neigh: grid[node]){
      if(visited[neigh] == -1 && visited[node] ==0){
        q.push(neigh);
        visited[neigh] = 1;
      }
      
      else if(visited[neigh] == -1 && visited[node] ==1) {
        q.push(neigh);
        visited[neigh] = 0;   
      }

      else if(visited[node] == visited[neigh]) return false;
    }

  }

  return true;
}
 
int main(){
  int n,m;
  cin>>n>>m;

  vector<vector<int>> grid(n+1);
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    grid[x].push_back(y);
    grid[y].push_back(x);
  }

  vector<int> visited(n+1,-1);

  bool ans = true;
  for(int i=1;i<=n;i++){
    if(visited[i] == -1) {
      if(!bfs(i,visited,grid)){
        ans = false;
        break;
      }
    }
  }

  if(ans){
    for(int i=1;i<=n;i++){
      cout<<visited[i]+1<<" ";
    }
  }
  else cout<<"IMPOSSIBLE"<<endl;
    
}