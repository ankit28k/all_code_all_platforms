#include<bits/stdc++.h>
using namespace std;

// int fun(int idx,int prev,int k,int l,vector<pair<int,int>>& arr,vector<vector<vector<int>>>& dp){
//     if(idx==arr.size()) {
//         int pvpos = arr[prev].first , pvsp = arr[prev].second ;
//         return (l - pvpos)*pvsp;
//     }

//     if(dp[idx][prev][k] != -1) return dp[idx][prev][k];

//     int prevpos = arr[prev].first , prevsp = arr[prev].second , currpos = arr[idx].first ;
//     int nt = (currpos - prevpos)*prevsp + fun(idx+1,idx,k,l,arr,dp);

//     int t= 1e9;
//     if(k>0){
//         t = fun(idx+1,prev,k-1,l,arr,dp);
//     }
    
//     return dp[idx][prev][k] = min(t,nt);
// }

int fun(int idx,int k,int l,int n,vector<pair<int,int>>& arr,vector<vector<int>>& dp){
    
    if(idx==n-1) {
        int pvpos = arr[idx].first , pvsp = arr[idx].second ;
        return (l - pvpos)*pvsp;
    }

    if(dp[idx][k] != -1) return dp[idx][k];
    int ans =1e9;

    // CHANGED: Added the option to go straight to 'l' by deleting ALL remaining signs.
    if(k >= n - 1 - idx) {
        int pvpos = arr[idx].first , pvsp = arr[idx].second ;
        ans = (l - pvpos)*pvsp;
    }

    for(int i=idx+1;i<n;i++){
        if(k>=i-idx-1){
            int pvpos = arr[idx].first , pvsp = arr[idx].second , currpos = arr[i].first;
            int temp = (currpos - pvpos)*pvsp + fun(i,k-(i-idx-1),l,n,arr,dp);
            ans = min(ans,temp);
        }
    }

    return dp[idx][k] = ans;
}


int main(){
    int n,l,k;
    cin>>n>>l>>k;
    vector<int> pos(n),val(n);
    for(int i=0;i<n;i++) cin>>pos[i];
    for(int i=0;i<n;i++) cin>>val[i];

    vector<pair<int,int>> arr(n);
    
    for(int i=0;i<n;i++){
        arr[i] = {pos[i],val[i]};
    }

    //vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
    //int ans = fun(1,0,k,l,arr,dp);

    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    int ans = fun(0,k,l,n,arr,dp);
    cout<<ans<<endl;


}