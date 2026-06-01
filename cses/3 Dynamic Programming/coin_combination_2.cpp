#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  for(int idx =0;idx<=n;idx++) dp[idx][0] = 1;

  for(int idx=1;idx<=n;idx++){
    for(int left=0;left<=x;left++){

      int t=0,nt=0;
      if(left>=arr[idx-1]) t = dp[idx][left-arr[idx-1]];
      nt = dp[idx-1][left];

      dp[idx][left] = (nt+t)%mod;
    }
  }

  cout<<dp[n][x]<<endl;

}