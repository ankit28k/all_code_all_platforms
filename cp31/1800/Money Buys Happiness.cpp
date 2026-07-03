#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int left,int n,int x,vector<pair<long long,long long>>& arr,vector<vector<long long>>& dp){
    if(idx==n) return 0;

    if(dp[idx][left] != -1) return dp[idx][left];
    long long nt = fun(idx+1,left+x,n,x,arr,dp);
    long long t=0;
    if(left>=arr[idx].first) t = arr[idx].second + fun(idx+1,left+x-arr[idx].first,n,x,arr,dp);

    return dp[idx][left] = max(t,nt);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<pair<long long,long long>> arr(n);

        for(int i=0;i<n;i++){
            int c,h;
            cin>>c>>h;
            arr[i] = {c,h};
        }

        long long maxi= n*x;
        vector<vector<long long>> dp(n,vector<long long>(maxi+1,-1));
        cout<<fun(0,0,n,x,arr,dp)<<endl;
    }

}