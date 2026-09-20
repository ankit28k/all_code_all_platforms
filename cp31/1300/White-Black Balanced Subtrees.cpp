#include<bits/stdc++.h>
using namespace std;

void dfs(int x,vector<vector<int>>& gr,vector<bool>& vis,string& s,vector<vector<long long>>& dp,long long& ans){

    vis[x] = true;
    dp[x][0] = s[x-1]=='B';
    dp[x][1] = s[x-1]=='W';

    for(int cx:gr[x]){
        if(!vis[cx]){
            dfs(cx,gr,vis,s,dp,ans);

            dp[x][0] += dp[cx][0];
            dp[x][1] += dp[cx][1];
        }
    }

    if(dp[x][0]==dp[x][1]) ans++;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> gr(n+1);
        for(int i=0;i<n-1;i++) {
            int x;
            cin>>x;
            gr[x].push_back(i+2);
        }

        string s;
        cin>>s;

        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        vector<bool> vis(n+1,false);

        long long ans=0;
        dfs(1,gr,vis,s,dp,ans);
        cout<<ans<<endl;
    }

}