#include <bits/stdc++.h>
using namespace std;


bool checkcons(int x,int y,int n,int m){
  return x>=0 && y>=0 && x<n && y<m;
}

vector<pair<int,int>> moves = {
  {1,0} , {-1,0} , {0,1} ,{0,-1}
};

int dfs(pair<int,int> src ,vector<vector<int>>& grid ,vector<vector<bool>>& vis,int n,int m){

  int x = src.first , y = src.second;
  vis[x][y] = true;
  int temp= grid[x][y];

  for(auto mov: moves){
    int cx = x + mov.first , cy = y+mov.second;

    if(checkcons(cx,cy,n,m) && !vis[cx][cy] && grid[cx][cy] != 0){
      temp += dfs({cx,cy},grid,vis,n,m);
    }
  }

  return temp;

}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid(n,vector<int>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>grid[i][j];
      }
    }

    int ans =0;

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(!vis[i][j]  && grid[i][j] != 0 ){
          ans = max(ans,dfs({i,j},grid,vis,n,m));
        }
      }
    }

    cout<<ans<<endl;


  }
}