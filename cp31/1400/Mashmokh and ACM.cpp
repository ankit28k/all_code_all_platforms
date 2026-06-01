#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 +7;

void numoffactor(vector<vector<int>>& fac,int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i%j ==0) fac[i].push_back(j);
        }
    }
}

int fun(vector<vector<int>>& fac,int n,int k,vector<vector<int>>& dp){
    
    if(k<=1 ) return 1; // if last is taken by n ....then only k-1 left
    
    // dp[n][k] tracks BOTH the current number (n) AND remaining length (k). 
    // If we only used dp[n], the program would mix up the answers for sequences of different lengths. 
    // Example: If we only used dp[n], fun(2, 2) would store its answer in dp[2]. 
    // Later, fun(2, 3) would see dp[2] is already filled and wrongly return the 
    // answer for length 2, instead of calculating the correct answer for length 3.
    
    if(dp[n][k] != -1) return dp[n][k];

    int sum =0;
    for(int f : fac[n]){
        sum = (sum + fun(fac,f,k-1,dp)) % mod;
    }

    return dp[n][k]  = sum%mod;
}

int main(){ 

    int n,k;
    cin>>n>>k;

    vector<vector<int>> fac(n+1); 
    
    numoffactor(fac,n);
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));

    int sum=0;
    for(int i=1;i<=n;i++){
        
        sum = (sum + fun(fac,i,k,dp))%mod;
    }

    cout<<sum<<endl;
    

}