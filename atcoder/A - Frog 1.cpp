#include<bits/stdc++.h>
using namespace std;

int dp[100001];
int fj(vector<int>& arr,int n){
  if(dp[n] != -1) return dp[n];

  if(n==0) return dp[n] = 0;
  if(n==1) return dp[n] = abs(arr[1]-arr[0]);
  
  return dp[n] = min( fj(arr,n-1) + abs(arr[n] - arr[n-1]),
                      fj(arr,n-2) + abs(arr[n] - arr[n-2]) );
}

// int func(int i,vector<int>& h) {
//     if(i == 0) return 0;
//     if(dp[i] != -1) return dp[i];

//     int cost = INT_MAX;

//     // way 1: jump from (i-1)
//     cost = min(cost, func(i-1) + abs(h[i] - h[i-1]));

//     // way 2: jump from (i-2)
//     if(i > 1)
//       cost = min(cost, func(i-2) + abs(h[i] - h[i-2]));

//     return dp[i] = cost;
// }

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  memset(dp,-1,sizeof(dp));
  cout<<fj(arr,n-1)<<endl;
}