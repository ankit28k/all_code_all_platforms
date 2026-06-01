#include <bits/stdc++.h>
using namespace std;

int lcs(string& a,string& b){
  int n = a.length() , m = b.length();
  vector<vector<int>> dp(n+1 , vector<int>(m+1,0));

  int ans = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i-1]==b[j-1]) {
        dp[i][j] = 1+ dp[i-1][j-1];
        ans = max(ans,dp[i][j]);
      }
      else dp[i][j]=0;
    }
  }

  return ans;
}

int main(){
  int t;
  cin>>t;
  while (t--)
  {
    string a,b;
    cin>>a>>b;
    cout<< a.length() + b.length() - 2*lcs(a,b) <<endl;
  }
  
}