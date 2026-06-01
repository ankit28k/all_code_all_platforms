#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,m;
  cin >> n>>m;

  vector<vector<int>> grid(n+1);
  vector<int> indegree(n+1);

  for(int i=0;i<m;i++){
    int a,b;
    cin >>a>>b;
    grid[b].push_back(a);
    indegree[a]++;

  }

  queue<int> q;
  vector<int> topo;

  for(int i=1;i<=n;i++) if(indegree[i]==0) q.push(i);

  while(!q.empty()){
    int node = q.front();
    q.pop();

    topo.push_back(node);
    
    for (auto it : grid[node]) {

        indegree[it]--;
        if (indegree[it] == 0) {
          q.push(it);
        }
    }


  }

  reverse(topo.begin(),topo.end());
  
  // if(topo.size() == n){
  //   for(int i=0; i <topo.size();i++) cout<<topo[i]<<" ";
  // }

  //they’re just about signed/unsigned type mismatch.
  //topo.size() returns a size_t (an unsigned long). 
  // n and i are int (signed).

  if ((int)topo.size() == n) {
    for (int i = 0; i < (int)topo.size(); i++) cout << topo[i] << " ";
  }

  
  else cout<<"IMPOSSIBLE"<<endl;
  


}