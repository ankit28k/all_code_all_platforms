#include <bits/stdc++.h>
using namespace std;

void dfs(int source,vector<int> &visited,vector<vector<int>> &adj){
 
 visited[source] = 1;
 for(auto neigh:adj[source]){
  if(!visited[neigh]) dfs(neigh,visited,adj);
 }

}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n+1);

  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> visited(n+1,0);
  vector<int> ans;
  int count=0;

  for(int i=1;i<=n;i++){
    if(!visited[i]) {
      dfs(i,visited,adj);
      ans.push_back(i);
      count++;
    }
  }

  cout<<count-1<<endl;

  for (int i = 0; i < (int)ans.size() - 1; i++) {
    cout << ans[i] << " " << ans[i + 1] << endl;
  }

  // for(int i=0;i<ans.size()-1;i++){
  //   cout<<ans[i]<<" "<<ans[i+1]<<endl;
  // }


}