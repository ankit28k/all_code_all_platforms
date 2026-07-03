#include<bits/stdc++.h>
using namespace std;

int fun(int i,int j,string& s, vector<vector<long long>>& dp){
    if(i>j) return 0;
    if(i==j) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    long long ans = 0;

    if (s[i] == s[j]){
        int t = 1+ fun(i, j - 1, s, dp);
        int nt = fun(i + 1, j, s, dp) ;
    }
    else{
        int a = fun(i + 1, j, s, dp);
        int b = fun(i, j - 1, s, dp) ;
        int c = fun(i + 1, j - 1, s, dp);
    } 
    
    return dp[i][j] = ans;
}
int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++) {
        char c;
        cin>>c;
        s.push_back(c);
    }

    vector<vector<long long>> dp(n, vector<long long>(n, -1));
    
    cout << fun(0, n - 1, s, dp) <<endl;

}
