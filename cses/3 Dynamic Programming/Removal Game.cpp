#include<bits/stdc++.h>
using namespace std;

long long fun(int l,int r,int player,vector<long long>& arr,vector<vector<vector<long long>>>& dp){

    if(l>r) return 0;

    if(dp[player][l][r] != -1) return dp[player][l][r];

    if(player == 0){
        long long first = arr[l] + fun(l+1,r,1,arr,dp);
        long long last = arr[r] + fun(l,r-1,1,arr,dp);

        return dp[player][l][r] = max(first,last);
    }

    else{
        long long first =fun(l+1,r,0,arr,dp);
        long long last = fun(l,r-1,0,arr,dp);

        return dp[player][l][r] = min(first,last);
    }
}
int main(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    //M1
    // vector<vector<vector<long long>>> dp(2,vector<vector<long long>>(n,vector<long long>(n,-1)));
    // cout<<fun(0,n-1,0,arr,dp)<<endl;


    //M2
    // vector<vector<vector<long long>>> dp(2,vector<vector<long long>>(n+1,vector<long long>(n+1,0)));
    
    // for(int l=n-1;l>=0;l--){
    //     for(int r=l;r<n;r++){
            
    //         for(int player =0;player<2;player++){
    //             if(player==0){
    //                 long long first = arr[l] ,last = arr[r];

    //                 if(l+1<=r) first += dp[1][l+1][r];
    //                 if(l<=r-1) last+= dp[1][l][r-1];

    //                 dp[player][l][r] = max(first,last);
    //             }

    //             else{
    //                 long long first = 0 , last=0;
    //                 if(l+1<=r) first = dp[0][l+1][r];
    //                 if(l<=r-1) last = dp[0][l][r-1];

    //                 dp[player][l][r] = min(first,last);
    //             }
    //         }

    //     }
    // }

    // cout<<dp[0][0][n-1]<<endl;


    //M3 space optimized rest give runtime error due to large amount of memory
    vector<vector<long long>> dp0(n,vector<long long>(n,0));
    vector<vector<long long>> dp1(n,vector<long long>(n,0));

    
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            
            long long first = arr[l], last = arr[r];
            if(l+1<=r) first += dp1[l+1][r];
            if(l<=r-1) last+= dp1[l][r-1];

            dp0[l][r] = max(first,last);

            first =0;
            last=0;
            if(l+1<=r) first= dp0[l+1][r];
            if(l<=r-1) last= dp0[l][r-1];

            dp1[l][r] = min(first,last);
            
        }
    }

    cout<<dp0[0][n-1]<<endl;
    

}