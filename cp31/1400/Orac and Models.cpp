#include<bits/stdc++.h>
using namespace std;

int fun(int prev, vector<int>& arr,vector<int>& dp,int n){

    if(prev>=n) return 0;

    if(dp[prev] != -1) return dp[prev];
    int maxi =0;

    for(int i=prev*2;i<=n;i+=prev){
        int take =0;
        if( arr[i] > arr[prev]) take = 1 + fun(i,arr,dp,n);
        maxi = max(maxi,take);
    }
    
    return dp[prev] = maxi;
}

//T(n)=n/1+n/2+n/3+n/4+...+n/n
//T(n)=n(1+1/2+1/3+...+1/n)
//1+1/2+1/3+...+1/n=O(logn)
//T(n)=O(nlogn)

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++)  cin>>arr[i];
        vector<int> dp(n+1,-1);

        int ans =1;
        for(int i=1;i<n;i++){
            ans = max(ans,1+fun(i,arr,dp,n));
        }

        cout<<ans<<endl;
        
    }

}