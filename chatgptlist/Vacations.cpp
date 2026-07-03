#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int prev,vector<int>& arr,vector<vector<int>>& dp){

    // 1-> test....1-> sports
    if(idx<0) return 0;

    if(dp[idx][prev] != -1) return dp[idx][prev];

    int ans = arr.size();

    int curr = arr[idx];
    if(curr ==0) ans = min(ans,1+fun(idx-1,0,arr,dp));

    else if(curr==3){
        if(prev==0) ans = min({ans,fun(idx-1,1,arr,dp),fun(idx-1,2,arr,dp)});
        else if(prev==1) ans= min(ans,fun(idx-1,2,arr,dp));
        else if(prev==2) ans= min(ans,fun(idx-1,1,arr,dp));
    }

    else if(curr == 1){
        if(prev !=curr) ans = min(ans,fun(idx-1,1,arr,dp));
        // if(prev==0) ans = min(ans,fun(idx-1,1,arr,dp));
        // else if(prev==2) ans= min(ans,fun(idx-1,1,arr,dp));
        else if(prev==1) ans= min(ans,1+fun(idx-1,0,arr,dp));
        
    }

    else if(curr == 2){
        if(prev !=curr) ans = min(ans,fun(idx-1,2,arr,dp));
        else if(prev==2) ans= min(ans,1+fun(idx-1,0,arr,dp));
    }

    return dp[idx][prev] = ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<int>> dp(n,vector<int>(4,-1));
    cout<<fun(n-1,0,arr,dp)<<endl;

}