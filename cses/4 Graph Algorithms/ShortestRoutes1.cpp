#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;

  vector<vector<pair<long long,int>>> grid(n+1);
  
  for(int i=0;i<m;i++){
    int x ,y;
    long long wt;
    cin>>x>>y>>wt;
    grid[x].push_back({wt,y}); 

  }

  vector<long long> dist (n+1 , 1e18);
  dist[1] = 0;
  set<pair<long long,int>> st;

  st.insert({0,1}); 

  while(!st.empty()){
    auto top = *(st.begin());
    st.erase(top);

    long long wt = top.first;
    int node = top.second;

    if (wt > dist[node]) continue;

    for(auto it : grid[node]){
      long long edgewt = it.first;
      int edgenode = it.second;
      
      if(wt + edgewt < dist[edgenode]){
        
        if(dist[edgenode] != 1e9) st.erase({dist[edgenode],edgenode});
        dist[edgenode] =  wt + edgewt ;
        st.insert({dist[edgenode] , edgenode});
      }
    }


  }

  for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
  cout<<endl;

  
}