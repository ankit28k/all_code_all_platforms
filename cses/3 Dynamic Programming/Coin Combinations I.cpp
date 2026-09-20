#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int fun(int left,int n,vector<int>& arr,vector<long long>& dp){

  if(left==0) return 1;
  
  if(dp[left] != -1) return dp[left];

  long long ans=0;
  for(int i=0;i<n;i++){
    if(left>=arr[i]){
      ans = (ans+fun(left-arr[i],n,arr,dp))%mod;
    }
  }
  return dp[left] = ans;

}
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  vector<long long> dp(x+1,-1);
  cout<<fun(x,n,arr,dp)<<endl;

}