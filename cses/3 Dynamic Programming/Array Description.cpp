#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int fun(int idx,int prev,int n,int m,vector<int>& arr,vector<vector<long long>>& dp){
    
    if(idx==n) return 1;
    
    if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

    if(arr[idx]==0){
        long long ans=0;
        int st,end;
        if(prev==-1){
            st = 1;
            end =m;
        }
        else {
            st = max(1,prev-1);
            end = min(prev+1,m);
        }
        for(int i=st;i<=end;i++){
            ans = (ans + fun(idx+1,i,n,m,arr,dp))%mod;
        }
        return dp[idx][prev+1] = ans%mod;
    }
    else {
        if(prev == -1 || abs(arr[idx]-prev)<=1) return dp[idx][prev+1] = (fun(idx+1,arr[idx],n,m,arr,dp))%mod;
        else return dp[idx][prev+1] = 0;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<long long>> dp(n,vector<long long>(m+2,-1));
    cout<<fun(0,-1,n,m,arr,dp)<<endl;
    
}