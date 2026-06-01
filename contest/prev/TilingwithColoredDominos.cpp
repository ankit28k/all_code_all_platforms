#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MAXNUM = 100000; // n is max 1e5

//TLE as calculating for every test case

// int fun(int n){
//   if(n<=1) return 1;
//   vector<long long> dp(n+1);

//   dp[0] = 1 ;
//   dp[1] = 1;
//   for(int i=2;i<=n;i++){
//     dp[i] = (dp[i-2]*2 + dp[i-1])%mod; // 2 different colours
//   }

//   return dp[n];
// }
int main(){

  vector<long long> dp(MAXNUM+1);

  dp[0] = 1 ;
  dp[1] = 1;
  for(int i=2;i<= MAXNUM;i++){
    dp[i] = (dp[i-2]*2 + dp[i-1])%mod; // 2 different colours
  }

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    cout<<dp[n]<<endl;
  }
}