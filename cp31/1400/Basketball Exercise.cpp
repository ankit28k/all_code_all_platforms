#include<bits/stdc++.h>
using namespace std;

long long fun(vector<long long>& arr,vector<long long>& brr,int idx,int last,vector<vector<long long>>& dp){

    if(idx<0) return 0;

    if(dp[idx][last] != -1) return dp[idx][last];

    if(last == 0){

        long long take = brr[idx] + fun(arr,brr,idx-1,1,dp);
        long long notake = fun(arr,brr,idx-1,0,dp);

        return dp[idx][last] = max(take,notake);

    }

    else if(last == 1){
        
        long long take = arr[idx] + fun(arr,brr,idx-1,0,dp);
        long long notake = fun(arr,brr,idx-1,1,dp);

        return dp[idx][last] = max(take,notake);
    }

    return -1;

}
int main(){
    
    int n;
    cin>>n;
    vector<long long> arr(n) , brr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>brr[i];

    vector<vector<long long>> dp(n,vector<long long>(2,-1));
    long long ans = max(arr[n-1] + fun(arr,brr,n-2,0,dp),brr[n-1] + fun(arr,brr,n-2,1,dp));
    cout<<ans<<endl;
    

}