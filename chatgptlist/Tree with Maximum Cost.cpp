#include<bits/stdc++.h>
using namespace std;

void fun(int x,int par,vector<vector<int>>& gr,vector<int>& arr,vector<vector<long long>>& dp){

    dp[x][1] = arr[x];
    for(int cx:gr[x]){
        if(cx==par) continue;

        fun(cx,x,gr,arr,dp);
        dp[x][0] += dp[cx][0] + dp[cx][1];
        dp[x][1] += dp[cx][1];
        
    }
}

void fun2(int x,int par,long long sum,vector<vector<int>>& gr,vector<long long>& val,vector<vector<long long>>& dp){

    for(int cx:gr[x]){
        if(cx==par) continue;

        long long cval = val[x] + sum - 2*(dp[cx][1]);
        val[cx] = cval; 
        fun2(cx,x,sum,gr,val,dp);
        
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];

    vector<vector<int>> gr(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<vector<long long>> dp(n+1,vector<long long>(2,0));

    fun(1,-1,gr,arr,dp);

    vector<long long> val(n+1);
    val[1] =  dp[1][0]; 

    long long sum=0;
    for(int i=1;i<=n;i++) sum+=arr[i];

    fun2(1,-1,sum,gr,val,dp);
    long long ans=0;
    for(auto x:val) ans = max(ans,x);

    cout<<ans<<endl;

}