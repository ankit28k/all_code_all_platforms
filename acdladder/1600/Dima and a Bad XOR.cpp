#include<bits/stdc++.h>
using namespace std;

bool fun(int idx,int sum,vector<vector<int>>& arr,int n,int m,vector<vector<int>>& dp,vector<vector<int>>& path){

    if(idx==n) return sum>0;

    if(dp[idx][sum] != -1) return dp[idx][sum];
    
    for(int j=0;j<m;j++){
        if(fun(idx+1,sum^arr[idx][j],arr,n,m,dp,path)) {
            path[idx][sum] = j;
            return dp[idx][sum] = true;
        }
    }

    return dp[idx][sum] = false;

}
int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    
    vector<vector<int>> dp(n,vector<int>(1023+1,-1));
    vector<vector<int>> path(n,vector<int>(1023+1,-1));

    bool ans = fun(0,0,arr,n,m,dp,path);
    if(!ans) cout<<"NIE"<<endl;

    else {
        cout<<"TAK"<<endl;
        vector<int> ans;

        int idx = 0;
        int sum = 0;

        while(idx < n){

            int j = path[idx][sum];
            ans.push_back(j+1);

            sum = sum^arr[idx][j];

            idx++;
        }

        for(int x : ans) cout<<x<<" ";
        cout<<endl;
    }

}