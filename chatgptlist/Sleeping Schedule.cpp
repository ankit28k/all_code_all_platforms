#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int prev,vector<int>& arr,int n,int h,int l,int r,vector<vector<int>>& dp){
    if(idx==n) return 0;

    if(dp[idx][prev] != -1) return dp[idx][prev];

    int curr1 = (prev + arr[idx])%h , curr2 = (prev+arr[idx]-1)%h;
    int t1=0,t2=0;
    if(curr1<=r && curr1>=l) t1 = 1+fun(idx+1,curr1,arr,n,h,l,r,dp);
    else t1 = fun(idx+1,curr1,arr,n,h,l,r,dp);

    if(curr2<=r && curr2>=l) t2 = 1+fun(idx+1,curr2,arr,n,h,l,r,dp);
    else t2 = fun(idx+1,curr2,arr,n,h,l,r,dp);

    return dp[idx][prev] = max(t1,t2);
}

int main(){
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<int>> dp(n,vector<int>(h,-1));
    cout<<fun(0,0,arr,n,h,l,r,dp)<<endl;

}