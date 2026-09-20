#include <bits/stdc++.h>
using namespace std;

long long fun(int i,int j,int p,vector<int>& arr,vector<vector<vector<long long>>>& dp){

    if(i>j) return dp[i][j][p] =0;
    if(i==j) {
        if(p==1) return dp[i][j][p] = arr[i];
        return dp[i][j][p] =0;
    }

    if(dp[i][j][p] != -1) return dp[i][j][p];
    if(p==1){
        long long l = arr[i] + fun(i+1,j,0,arr,dp);
        long long r = arr[j] + fun(i,j-1,0,arr,dp);
        return dp[i][j][p] = max(l,r);
    }
    else {
        long long l = fun(i+1,j,1,arr,dp);
        long long r = fun(i,j-1,1,arr,dp);
        return dp[i][j][p]= min(l,r);
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    long long sum=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    

    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
    fun(0,n-1,1,arr,dp);

    if(2*dp[0][n-1][1]>=sum) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}
