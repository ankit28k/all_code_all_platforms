#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int n,vector<int>& arr,vector<int>& dp){
    if(idx<0 || idx>=n) return 0;

    if(dp[idx] != -1) return dp[idx];
    int ans=1;
    for(int i =idx+1;i<n;i++){
        if(arr[i]<arr[idx]) ans = max(ans,1+fun(i,n,arr,dp));
        if(arr[i]>=arr[idx]) break;
    }

    for(int i =idx-1;i>=0;i--){
        if(arr[i]<arr[idx]) ans = max(ans,1+fun(i,n,arr,dp));
        if(arr[i]>=arr[idx]) break;
    }

    return dp[idx] = ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans=1;
    vector<int> dp(n,-1);
    for(int i=0;i<n;i++){ 
        ans = max(ans,fun(i,n,arr,dp));
    }
    cout<<ans<<endl;

}