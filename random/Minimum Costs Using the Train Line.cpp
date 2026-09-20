#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int prev,vector<int>& red,vector<int>& blue,int bc,vector<vector<int>>& dp){

    if(idx==0) {
        if(prev==0) return dp[idx][prev] = red[idx];
        return dp[idx][prev] = blue[idx]+ bc;
    }

    if(dp[idx][prev] != -1) return dp[idx][prev] ;

    int cr ,cb;

    if(prev==1) {//current at blue
        cb = min(blue[idx] + fun(idx-1,1,red,blue,bc,dp) , blue[idx] + bc + fun(idx-1,0,red,blue,bc,dp));
        return dp[idx][prev] = cb;
    }
    else {//current at red
        cr = min(red[idx] + fun(idx-1,1,red,blue,bc,dp) , red[idx] + fun(idx-1,0,red,blue,bc,dp));
        return dp[idx][prev] = cr;
    }
    
}
int main(){
    int n;
    cin>>n;

    vector<int> red(n),blue(n);
    for(int i=0;i<n;i++) cin>>red[i];
    for(int i=0;i<n;i++) cin>>blue[i];
    int bc;
    cin>>bc;

    vector<vector<int>> dp(n,vector<int>(2,-1));
    fun(n-1,0,red,blue,bc,dp);
    fun(n-1,1,red,blue,bc,dp);

    vector<int> ans(n+1);
    ans[0]=0;
    for(int i=1;i<=n;i++) {
        ans[i] = min(dp[i-1][0],dp[i-1][1]);
    }
    for(int x:ans) cout<<x<<" ";
    cout<<endl;


    

}