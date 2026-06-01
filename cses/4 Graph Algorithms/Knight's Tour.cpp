#include<bits/stdc++.h>
using namespace std;

bool dfs(int x,int y,vector<vector<bool>>& vis,vector<pair<int,int>>& move,int cnt,vector<vector<int>>& ans){
    vis[x][y] = true;
    ans[x][y] = cnt;
    
    for(auto mov: move){
        int cx = mov.first + x,cy = mov.second + y;
        if(cx>=1 && cy>=1 && cx<=8 && cy<=8 && !vis[cx][cy]){
            dfs(cx,cy,vis,move,cnt+1,ans);
        }
    }
}
int main(){
    int x,y;
    cin>>x>>y;

    vector<vector<bool>> vis(9,vector<bool>(9,false));
    vector<pair<int,int>> move = {
        {-2,1},{-2,-1},
        {2,1},{2,-1},
        {1,2},{1,-2},
        {-1,2},{-1,-2}
    };
    vector<vector<int>> ans(9,vector<int>(9));
    
    dfs(y,x,vis,move,1,ans);

    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


}