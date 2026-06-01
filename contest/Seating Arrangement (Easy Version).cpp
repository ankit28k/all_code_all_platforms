#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int j,int s,string& a,vector<vector<int>>& dp){

    if(j<0) return -1;
    if(idx==0){
        if(j==0) return 0;
        else return -1;
    }

    if(dp[idx][j] != -2) return dp[idx][j];

    int ans = fun(idx-1,j,s,a,dp);
    char ch = a[idx-1];

    if(ch == 'I' || ch=='A'){
        int prev = fun(idx-1,j-1,s,a,dp);
        if(prev != -1) ans = max(ans,prev+1);
    }

    if(ch == 'E' || ch=='A'){
        int prev = fun(idx-1,j,s,a,dp);
        if(prev != -1){
            long long t = prev;
            long long part = 1LL*j*s-t;
            if(part>0) ans = max(ans,prev+1);
        }
    }

    return dp[idx][j] = ans;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,s;
        cin>>n>>x>>s;

        string a;
        cin>>a;
        vector<vector<int>> dp(n+1,vector<int>(x+1,-2));
        int ans=0;
        for(int i=0;i<=x;i++){
            ans = max(ans,fun(n,i,s,a,dp));
        }
        cout<<ans<<endl;
    }

}