#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int prev,int n,vector<pair<pair<int,int> ,int>>& arr,vector<vector<int>>& dp){
    if(idx==n) return 0;

    if(dp[idx][prev] != -1) return dp[idx][prev];

    int t=0 , st = arr[idx].first.first , end = arr[idx].first.second , rew = arr[idx].second;
    int nt = fun(idx+1,prev,n,arr,dp);

    if(st>prev) t = rew + fun(idx+1,end,n,arr,dp);

    return dp[idx][prev] = max(t,nt);
}
int main(){
    int n;
    cin>>n;
    vector<pair<pair<int,int> ,int>> arr(n);

    unordered_map<int,pair<int,int>> mp;
    int p=0;
    for(int i=0;i<n;i++) {
        int a,b,r;
        cin>>a>>b>>r;
        mp[a] = {b,r};
        
    }

    vector<vector<int>> dp(n,vector<int>(p+1,-1));
    cout<<fun(0,0,n,arr,dp)<<endl;

}