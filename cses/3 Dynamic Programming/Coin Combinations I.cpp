#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int fun(int idx,int left,vector<int>& arr,vector<vector<int>>& dp){

  if(idx <0) return 0;
  if(left==0) return 1;

  if(dp[idx][left] != -1) return dp[idx][left];

  int t=0,nt=0;
  if(left>=arr[idx]) t = fun(idx,left-arr[idx],arr,dp);
  nt = fun(idx-1,left,arr,dp);

  return dp[idx][left] = (t + nt)%mod;

}
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  vector<vector<int>> dp(n,vector<int>(x+1,-1));
  cout<<fun(n-1,x,arr,dp)<<endl;

}