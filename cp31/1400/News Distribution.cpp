#include<bits/stdc++.h>
using namespace std;

int dfs(int src,int val,vector<vector<int>>& grid,vector<int>& vis){

    vis[src] = val;
    int ans = 1;

    for(auto neigh : grid[src]){
        if(vis[neigh]==0) {
            ans += dfs(neigh,val,grid,vis); 
        }
    }

    return ans;

}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid(n+1);
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        vector<int> temp(k);
        for(int j=0;j<k;j++) cin>>temp[j];

        for(int j=0;j<k-1;j++){

            grid[temp[j]].push_back(temp[j+1]);
            grid[temp[j+1]].push_back(temp[j]);
        }
    }

    vector<int> vis(n+1,0);
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            int k = dfs(i,i,grid,vis) ;
            mp[i] = k;
        }
    }

    for(int i=1;i<=n;i++) cout<<mp[vis[i]]<<" ";
    cout<<endl;
    

}