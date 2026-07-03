#include<bits/stdc++.h>
using namespace std;

long long fun(int idx,int n,int m,int k,vector<long long>& psum,vector<vector<long long>>& dp){

    if(k==0) return 0;
    if(idx == n) return 0;
    
    if(dp[idx][k] != -1) return dp[idx][k];

    long long t=0,nt=0;
    if(idx+m<=n) t = psum[idx+m] - psum[idx] + fun(idx+m,n,m,k-1,psum,dp);
    nt = fun(idx+1,n,m,k,psum,dp);

    return dp[idx][k] = max(t,nt);
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<long long> psum(n+1);
    psum[0]=0;
    psum[1] = arr[0];
    for(int i=2;i<=n;i++) psum[i] = psum[i-1]+arr[i-1];

    vector<vector<long long>> dp(n,vector<long long>(k+1,-1));
    cout<<fun(0,n,m,k,psum,dp)<<endl;

}