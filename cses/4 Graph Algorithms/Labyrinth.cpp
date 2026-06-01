#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> movements = {
  {1,0},{0,1},{-1,0},{0,-1}
};
 

int main(){
  int r,c;
  cin>>r>>c;

  vector<vector<char>> grid(r,vector<char>(c));
  vector<vector<bool>> visited(r,vector<bool>(c,false));
  vector<vector<int>> level(r,vector<int>(c));

  vector<vector<pair<int,int>>> parent(r, vector<pair<int,int>>(c, {-1,-1}));

  queue<pair<int,int>> q;
  pair<int,int> start , des;

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin>>grid[i][j]; 
      if(grid[i][j] == '#') visited[i][j] = true;
      if(grid[i][j]=='A') {

        start = {i,j};
        q.push({i,j});
        visited[i][j] = true;
        level[i][j] = 0;
      }

      if(grid[i][j]=='B') des = {i,j};
    }
  }

  


  while(!q.empty()){
    
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for( auto movement: movements){
      int childx = x + movement.first;
      int childy = y + movement.second;

      if(childx >= 0 && childx < r && childy >= 0 && childy < c && !visited[childx][childy]) {
        q.push({childx,childy});
        visited[childx][childy] = true ;
        level[childx][childy] = level[x][y] +1;
        parent[childx][childy] = {x, y};

      }

    }

  }

  if(visited[des.first][des.second]) {
    cout << "YES" << endl;
    cout << level[des.first][des.second] << endl;
    
    string path;
    pair<int,int> cur = des;
    
    while (cur != start) { // q.front() is start 'A', but queue is empty now, so let's store start separately

      pair<int,int> p = parent[cur.first][cur.second];

      if (p.first == cur.first) { // Same row, must be left or right
        
        if (p.second == cur.second + 1) path.push_back('L'); // parent is to the right, so moved left to get here
        else if (p.second == cur.second - 1) path.push_back('R');
      } 
      
      else if (p.second == cur.second) {  // Same column, must be up or down
       
        if (p.first == cur.first + 1) path.push_back('U'); // parent is below, so moved up to get here
        else if (p.first == cur.first - 1) path.push_back('D');
      }

      cur = p;

    }

    reverse(path.begin(), path.end());
    cout << path << endl;
  } 
  
  else  cout << "NO" << endl;
   
 

}