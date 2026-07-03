#include<bits/stdc++.h>
using namespace std;

// int fun(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
//     if(arr[i]*2>=arr[j]) return 0;

//     if(dp[i][j] != -1) return dp[i][j];

//     int l = 1 + fun(i+1,j,arr,dp);
//     int r = 1 + fun(i,j-1,arr,dp);

//     return dp[i][j] = min(l,r);
// }
    
int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());
    
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // cout<<fun(0,n-1,arr,dp)<<endl;

    int l=0,r=0;
    int ans=0;
    while(r<n){
        while(l<=r && arr[l]*2< arr[r]){
            l++;
        }

        ans = max(r-l+1,ans);
        r++;
    }
    cout<<n-ans<<endl;
}