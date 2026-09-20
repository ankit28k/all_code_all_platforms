#include<bits/stdc++.h>
using namespace std;

void fun(int x,int par,vector<vector<int>>& gr,vector<vector<long long>>& dp){

    long long nt =0,t=0; // 0 not take and 1 is take
    for(int cx:gr[x]){
        if(cx==par) continue;
        fun(cx,x,gr,dp);
        nt += max(dp[cx][0] , dp[cx][1]); //not take this vertex....hence choose max of the children and sum of all children
    }
    
    dp[x][0]=nt;

    for(int cx:gr[x]){
        if(cx==par) continue;
        long long temp =  nt - max(dp[cx][0],dp[cx][1]) + 1 + dp[cx][0]  ; //take this vertex
        t = max(t,temp);
    }
    dp[x][1] = t;

}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> gr(n+1);
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<vector<long long>> dp(n+1,vector<long long>(2,0));
    fun(1,0,gr,dp);

    cout<<max(dp[1][0] ,dp[1][1])<<endl;
}