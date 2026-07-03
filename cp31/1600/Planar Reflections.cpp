#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int fun(int idx,int n,int k,int dir,vector<vector<vector<int>>>& dp){
    if(k==1) return 1;
    if(idx<0 || idx>=n) return 1;
    
    if(dp[idx][k][dir]!=-1) return dp[idx][k][dir];
    int ans=0;
    if(dir==1){ //right
        int l = fun(idx-1,n,k-1,0,dp)%mod;
        int r = fun(idx+1,n,k,1,dp)%mod;

        ans = (ans+l+r)%mod;
    }

    else{ //left
        int l = fun(idx-1,n,k,0,dp)%mod;
        int r = fun(idx+1,n,k-1,1,dp)%mod;

        ans = (ans+l+r)%mod;
    }

    return dp[idx][k][dir] = ans;

}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        cout<<fun(0,n,k,1,dp)<<endl;
    }
    

}