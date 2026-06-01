#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> pr(n),pa(n);
    for(int i=0;i<n;i++) cin>>pr[i];
    for(int i=0;i<n;i++) cin>>pa[i];

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int idx=1;idx<=n;idx++){
        for(int left=0;left<=x;left++){
            int t =0,nt=0;
            if(left>=pr[idx-1]) t = pa[idx-1] + dp[idx-1][left-pr[idx-1]];
            nt = dp[idx-1][left];

            dp[idx][left] = max(t,nt);
            
        }
    }
    cout<<dp[n][x]<<endl;

}