#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int fun(int idx,int left,vector<int>& arr,vector<vector<int>>& dp,int n){
    if(left ==0) return 1;
    if(idx==n) return 0;

    if(dp[idx][left] != -1 ) return dp[idx][left];

    int t=0,nt=0;
    nt = fun(idx+1,left,arr,dp,n);
    if(left>=arr[idx]) t = fun(idx,left-arr[idx],arr,dp,n);

    return dp[idx][left] = (nt +t)%mod;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr = {1,2,3,4,5,6};

    vector<vector<int>> dp(7,vector<int>(n+1,-1));
    cout<<fun(0,n,arr,dp,n)<<endl;

}