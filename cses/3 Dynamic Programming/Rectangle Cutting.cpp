#include<bits/stdc++.h>
using namespace std;

int fun(int r,int c,vector<vector<int>>& dp){
    if(r==c) return 0;

    if(dp[r][c] != -1) return dp[r][c];
    int ans=INT_MAX;
    for(int i=1;i<r;i++){
        int val = 1+ fun(i,c,dp) + fun(r-i,c,dp);
        ans = min(ans,val);
    }

    for(int i=1;i<c;i++){
        int val = 1+ fun(r,i,dp) + fun(r,c-i,dp);
        ans = min(ans,val);
    }

    return dp[r][c] = ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    // vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
    // cout<<fun(a,b,dp)<<endl;

    vector<vector<int>> dp(a+1,vector<int>(b+1,0));

    for(int r=1;r<=a;r++){
        for(int c=1;c<=b;c++){

            if(r==c) continue;

            int ans=INT_MAX;
            for(int i=1;i<r;i++){
                int val = 1+ dp[i][c] + dp[r-i][c];
                ans = min(ans,val);
            }

            for(int i=1;i<c;i++){
                int val = 1+ dp[r][i] + dp[r][c-i];
                ans = min(ans,val);
            }

            dp[r][c] = ans;
        }
    }

    cout<<dp[a][b]<<endl;
}