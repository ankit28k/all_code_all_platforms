#include<bits/stdc++.h>
using namespace std;

long long fun(int k,int start,int end,vector<vector<vector<long long>>>& dp){
    if(k==0) return start;
    if(dp[k][start][end] != -1 ) return dp[k][start][end];
    int mid = start^end;
    return dp[k][start][end] = fun(k-1,start,mid,dp) + fun(k-1,mid,end,dp);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s,z;
        cin>>s>>z;

        vector<vector<vector<long long>>> dp(k+1,vector<vector<long long>>(2,vector<long long>(2,-1)));

        long long c0=0,c1=0,c2=0,c3=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0' && z[i]=='0') c0++;
            else if(s[i]=='0'&&z[i]=='1') c1++;
            else if(s[i]=='1'&&z[i]=='0') c2++;
            else c3++;
        }
        long long w01 = fun(k,0,1,dp)+1;
        long long w11 = fun(k,1,1,dp)+1;
        long long ans = w01*(c0*c1+c0*c2+c1*c3+c2*c3)+w11*(c0*c3+c1*c2);
        cout<<ans<<endl;

    }

}