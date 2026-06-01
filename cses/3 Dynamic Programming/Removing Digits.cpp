#include<bits/stdc++.h>
using namespace std;

int fun(int n,vector<int>& dp){

    if(n==0) return 0;

    if(dp[n] != -1) return dp[n];

    int t=n , ans=INT_MAX;
    while(t>0){
        int ld = t%10;
        if(ld != 0) ans = min(ans,1+fun(n-ld , dp));
        t = t/10;
    }

    return dp[n] = ans;

}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fun(n,dp)<<endl;
}