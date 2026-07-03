#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int prev,int cnt,int n,vector<long long>& arr,vector<vector<vector<long long>>>& dp){

    if(idx==n) return 0;
    
    if(dp[idx][prev][cnt] != -1) return dp[idx][prev][cnt];
    
    long long ans=1e9;
    if(prev==0){ //friend's turn....as 1->friend , 0->me
        long long tf = arr[idx] + fun(idx+1,1,1,n,arr,dp);
        long long tm =1e9;
        if(cnt<2) tm = fun(idx+1,0,2,n,arr,dp);

        ans = min({ans,tf,tm});
    }

    else if(prev==1){
        long long tm = fun(idx+1,0,1,n,arr,dp);
        long long tf =1e9;
        if(cnt<2)tf = arr[idx] + fun(idx+1,1,2,n,arr,dp);

        ans = min({ans,tf,tm});
    }

    return dp[idx][prev][cnt] = ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(2,vector<long long>(3,-1)));
        cout<<fun(0,0,2,n,arr,dp)<<endl;
    }

}