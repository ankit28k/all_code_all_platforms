#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int left,vector<int>& arr,vector<vector<int>>& dp,int n){
   
    if(idx==n) {
        if(left ==0) return 0;
        else return 1e9;
    }

    if(dp[idx][left] != -1 ) return dp[idx][left];

    int t=1e9,nt=1e9;
    nt = fun(idx+1,left,arr,dp,n);
    if(left>=arr[idx]) t = 1+ fun(idx,left-arr[idx],arr,dp,n);

    return dp[idx][left] = min(nt,t);
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    // vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
    
    // int ans = fun(0,x,arr,dp,n);
    // if(ans>=1e9) cout<<-1<<endl;
    // else cout<<ans<<endl;

    vector<vector<int>> dp(n+1,vector<int>(x+1,1e9));
    dp[n][0] =0;

    for(int idx =n-1;idx>=0;idx--){
        for(int left = 0;left<=x;left++){

            int t=1e9;
            int nt = dp[idx+1][left];
            if(left>=arr[idx]) t = 1+ dp[idx][left-arr[idx]];

            dp[idx][left] = min(nt,t);
        }
    }

    if(dp[0][x]>=1e9) cout<<-1<<endl;
    else cout<<dp[0][x]<<endl;


}