#include<bits/stdc++.h>
using namespace std;

int fun(int i,int j,int n,vector<int>& arr,vector<vector<int>>& dp){

    if(i>j) return 0;
    if(i==j) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = n;

    if(arr[i]==arr[j]){
        int val = fun(i+1,j-1,n,arr,dp);

        //ans = min(ans,val);
        // WHY MAX(1, VAL)?
        // If the inner segment is empty (e.g., the array is just "4 4"), 
        // fun() returns 0. But it still takes 1 operation to destroy "4 4".
        // max(1, val) forces the cost to be at least 1, preventing the 
        // total cost from falsely dropping to 0.

        ans = min(ans,max(1,val));
    }

    for(int k=i;k<j;k++){
        int val = fun(i,k,n,arr,dp) + fun(k+1,j,n,arr,dp);
        ans = min(ans,val);
    }

    return dp[i][j] = ans;

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<fun(0,n-1,n,arr,dp)<<endl;

}