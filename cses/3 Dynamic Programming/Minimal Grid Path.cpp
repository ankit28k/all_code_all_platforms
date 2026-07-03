#include<bits/stdc++.h>
using namespace std;

int fun(int i,int j,vector<vector<char>>& arr,vector<vector<int>>& dp){

    if(i==0 && j==0) return dp[i][j] = arr[i][j] -'A';

    if(dp[i][j] != -1) return dp[i][j];

    int l=INT_MAX,u=INT_MAX;
    if(i-1 >=0) u = (arr[i][j] -'A') + fun(i-1,j,arr,dp);
    
    if(j-1>=0) l = (arr[i][j] -'A') + fun(i,j-1,arr,dp);

    return dp[i][j] = min(l,u);
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

    vector<vector<int>> dp(n,vector<int>(n,-1)) ;
    fun(n-1,n-1,arr,dp);

    string ans="";
    int i=n-1,j=n-1;
    while(i>0 && j>0){
        ans.push_back(arr[i][j]);

        if(dp[i-1][j] - (arr[i-1][j]-'A') >= dp[i][j-1] - (arr[i][j-1]-'A')) i--;
        else j--;
    }

    while(i>0){
        ans.push_back(arr[i][j]);
        i--;
    }

    while(j>0){
        ans.push_back(arr[i][j]);
        j--;
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

}