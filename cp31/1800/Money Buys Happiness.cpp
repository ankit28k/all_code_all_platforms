#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int prev,int n,int x,vector<pair<long long,long long>>& arr,vector<vector<long long>>& dp){
    if(idx==n) return 0;

    if(dp[idx][prev] != -1) return dp[idx][prev];
    long long nt = fun(idx+1,prev,n,x,arr,dp);
    long long t=0;
    if(x*idx - prev>=arr[idx].first) t = arr[idx].second + fun(idx+1,prev+arr[idx].first,n,x,arr,dp);

    return dp[idx][prev] = max(t,nt);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<pair<long long,long long>> arr(n);

        long long maxi= 0;
        for(int i=0;i<n;i++){
            int c,h;
            cin>>c>>h;
            arr[i] = {c,h};
            maxi+=c;
        }

        vector<vector<long long>> dp(n,vector<long long>(maxi+1,-1));
        cout<<fun(0,0,n,x,arr,dp)<<endl;
    }

}