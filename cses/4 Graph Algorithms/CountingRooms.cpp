#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> movements = {
  {1,0},{0,1},{-1,0},{0,-1}
};

void dfs(int i,int j,int r, int c, vector<vector<bool>> &visited){ 

  visited[i][j] = true;
  for( auto movement: movements){
    int childx = i + movement.first;
    int childy = j + movement.second;

    if(childx >= 0 && childx < r && childy >= 0 && childy < c && !visited[childx][childy]) {
      dfs(childx,childy,r,c,visited);
    }

  }
}

int main(){
  int r,c;
  cin>>r>>c;

  vector<vector<char>> grid(r,vector<char>(c));
  vector<vector<bool>> visited(r,vector<bool>(c,false));

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin>>grid[i][j]; 
      if(grid[i][j] == '#') visited[i][j] = true;
    }
  }

  int count=0;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(!visited[i][j]) {
        dfs(i,j,r,c,visited);
        count++; 
      }
      
    }
  }
  
  cout<<count<<endl;

}