#include <bits/stdc++.h>
using namespace std;


int visited[8][8];
int level[8][8];

int getX(string s){
  return s[0] - 'a';
}

int getY(string s){
  return s[1] - '1';
}

vector<pair<int,int>> movements = {
  
  {1,2} , {1,-2} , {-1,2} , {-1,-2} , {2,1} , {2,-1} ,{-2,1},{-2,-1}
  
};

int bfs(string source,string destination) {
 
  queue<pair<int,int>> q;

  int sx = getX(source) , sy = getY(source);
  int dx = getX(destination) , dy = getY(destination);

  q.push({sx,sy});

  visited[sx][sy] =1;
  level[sx][sy] =0;

  while(!q.empty()){
    pair<int,int> node = q.front();
    int x = node.first , y=node.second;
    q.pop();

    if(x == dx && y == dy) return level[x][y];

    for(auto movement : movements){
      int childx = movement.first + x;
      int childy = movement.second + y;
      
      if (childx >= 0 && childx < 8 && childy >= 0 && childy < 8){
        if((!visited[childx][childy])  ){ 
          q.push({childx,childy});
          level[childx][childy] = level[x][y] + 1;
          visited[childx][childy] = 1;

        }
      }
        

    } 
  }

  return -1;
}

void reset(){
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      visited[i][j] = 0;
      level[i][j] = -1;
    }
  }
}

int main(){

  int t;
  cin >> t;
  while(t--){

    string s1,s2;
    cin >> s1 >> s2;

    reset();
    cout<<bfs(s1,s2)<<endl;
  }

}



    
    