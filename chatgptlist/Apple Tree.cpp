#include<bits/stdc++.h>
using namespace std;

void dfs(int x,vector<bool>& vis,vector<vector<int>>& gr,vector<long long>& dp){
    vis[x] = true;
    for(int cx:gr[x]){
        if(!vis[cx]) {
            dfs(cx,vis,gr,dp);
            dp[x] += dp[cx];
        }
    }
    if(dp[x]==0) dp[x]=1;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> gr(n+1);
        for(int i=0;i<n-1;i++) {
            int a,b;
            cin>>a>>b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }

        vector<long long> dp(n+1,0);
        vector<bool> vis(n+1,false);
        dfs(1,vis,gr,dp);

        int q;
        cin>>q;
        while(q--){
            int a,b;
            cin>>a>>b;
            cout<<dp[a]*dp[b]<<endl;
        }

    }

}