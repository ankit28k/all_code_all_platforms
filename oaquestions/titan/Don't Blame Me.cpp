#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int csb(int n){
    int ans=0;
    while(n){
        n = n&(n-1);
        ans++;
    }
    return ans;
}
int fun(int idx,int prev,int k,int n,vector<int>& arr,vector<vector<int>>& dp){

    if(idx==n){
        if(prev==-1) return 0;
        int sb= csb(prev);
        if(sb==k) return 1;
        else return 0;
    }

    if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

    int nt = fun(idx+1,prev,k,n,arr,dp);
    int val = arr[idx];
    if(prev != -1) val = arr[idx] & prev;
    int t = fun(idx+1,val,k,n,arr,dp);

    return dp[idx][prev+1] = (t+nt)%mod;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);

        int maxi=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            maxi = max(maxi,arr[i]);
        }
        vector<vector<int>> dp(n+1,vector<int>(maxi+5,-1));
        cout<<fun(0,-1,k,n,arr,dp)<<endl;
    }

}