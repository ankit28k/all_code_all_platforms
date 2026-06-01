#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 +7;
int fun(int i,int j,vector<vector<char>>& arr,vector<vector<int>>& dp){

    if(arr[i][j] == '*') return 0;
    if(i==0 && j==0 ) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int left=0,up=0;
    if(j- 1>=0 ) left = fun(i,j-1,arr,dp);
    if(i-1>=0 ) up = fun(i-1,j,arr,dp);

    return dp[i][j] = (left + up)%mod;
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>> arr(n,vector<char>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<fun(n-1,n-1,arr,dp)<<endl;

}