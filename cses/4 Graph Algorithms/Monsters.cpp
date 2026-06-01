#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n,m;
    vector<vector<char>> arr(n,vector<char>(m)) , path(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='M' || arr[i][j]=='A') {
                q.push({i,j});
                vis[i][j] = true;
            }
        }
    }

    vector<pair<int,int>> move = {
        {1,0},{-1,0},{0,-1} ,{0,1}
    };

    while(!q.empty()){
        int k = q.size();
        for(int i=0;i<k;i++){
            
        }
    }



}