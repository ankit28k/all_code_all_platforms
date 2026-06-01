#include<bits/stdc++.h>
using namespace std;

int dp[100001];
int fj(vector<int>& arr,int n,int k){
  if(dp[n] != -1) return dp[n];

  if(n==0) return dp[n] = 0; 
  
  int ans = INT_MAX;
  for(int i=1;i<=k;i++){
    if (n - i >= 0) {
        ans = min(ans, fj(arr, n - i, k) + abs(arr[n] - arr[n - i]));
      }
  }
  return dp[n] = ans;
}



int main(){
  int n,k;
  cin>>n>>k;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  memset(dp,-1,sizeof(dp));
  cout<<fj(arr,n-1,k)<<endl;
}