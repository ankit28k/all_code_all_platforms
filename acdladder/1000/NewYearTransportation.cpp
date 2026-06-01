#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> & graph,int src,int dst,vector<bool>& vis){
  vis[src] = true;
  for(auto neigh : graph[src]){
    if(neigh == dst) return true;
    if(!vis[neigh]) return dfs(graph,neigh,dst,vis);
  }

  return false;
}

int main(){
  int n , dst ;
  cin>>n>>dst;
  vector<int> arr(n+1);
  for(int i=1;i<=n-1;i++) cin>>arr[i];

  vector<vector<int>> graph(n+1);
  vector<bool> vis(n+1,false);

  for(int i=1;i<n;i++){
    int nxt = i + arr[i];
    if(nxt <= n) graph[i].push_back(nxt);
  }

  if(dfs(graph,1,dst,vis)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

}