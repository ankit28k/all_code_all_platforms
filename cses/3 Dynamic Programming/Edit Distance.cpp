#include<bits/stdc++.h>
using namespace std;

int fun(int i,int j,string& w1,string& w2,vector<vector<int>>& dp){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(dp[i][j] != -1) return dp[i][j];

    if(w1[i] != w2[j]){
        int ins = 1+fun(i,j-1,w1,w2,dp);
        int del = 1+fun(i-1,j,w1,w2,dp);
        int rep = 1+fun(i-1,j-1,w1,w2,dp);

        return dp[i][j] = min({ins,del,rep});
    }

    else return dp[i][j] = fun(i-1,j-1,w1,w2,dp);

}
int main(){
    string w1,w2;
    cin>>w1>>w2;
    int n = w1.length() , m = w2.length();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<fun(n-1,m-1,w1,w2,dp)<<endl;

}