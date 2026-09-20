#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<char>> gr(n,vector<char>(m));

    vector<bool> sfr(n,true),sfc(m,true);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin>>gr[i][j];
            if(gr[i][j]=='#') {
                sfr[i] = false;
                sfc[j] = false;
            }
        }
    }

    vector<vector<bool>> vis(n,vector<bool>(m));
    vector<vector<int>> lev(n,vector<int>(m));

    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(sfr[i] && sfc[j]){
                q.push({i,j});
                vis[i][j] = true;
                lev[i][j] = 0;
            }
        }
    }
    vector<pair<int,int>> move = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int x = t.first , y = t.second;

        for(auto mov:move){
            int cx = x+mov.first , cy = y+mov.second;
            if(cx>=0 && cx<n && cy>=0 && cy<m && !vis[cx][cy] && gr[cx][cy]=='.'){
                vis[cx][cy] = true;
                lev[cx][cy] = lev[x][y]+1;
                q.push({cx,cy});
            }
        }
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gr[i][j] == '.' && vis[i][j] && lev[i][j]<=k) ans++;
        }
    }

    cout<<ans<<endl;

}