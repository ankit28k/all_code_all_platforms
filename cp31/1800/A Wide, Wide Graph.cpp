#include<bits/stdc++.h>
using namespace std;

int dfs(int src, vector<vector<int>> &gr, vector<bool> &vis,vector<int>& dp){
    vis[src] = true;

    if(dp[src] != -1) return dp[src];
    int ans=0;

    bool neigh = false;
    for (int cx : gr[src]){
        if (!vis[cx]){
            neigh = true;
            ans = max(ans,dfs(cx, gr, vis,dp));
        }
    }

    if(neigh) return ans+1;
    else return 0;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> gr(n+1);
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    map<int,int> mp;
    

    vector<int> dp(n+1,-1);

    for(int i=1;i<=n;i++){
        if(dp[i]==-1) {
            vector<bool> vis(n + 1);
            dp[i] = dfs(i,gr,vis,dp);
        }
    }

    vector<int> temp;
    for(int i=1;i<=n;i++){
        temp.push_back(dp[i]);
    }

    sort(temp.begin(),temp.end());
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++){
        int lessthan = lower_bound(temp.begin(),temp.end(),i) - temp.begin();
        ans[i] = min(n,lessthan+1);
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    

}