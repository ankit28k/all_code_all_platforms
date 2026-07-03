#include<bits/stdc++.h>
using namespace std;

int fun(int n,set<int>& st,vector<int>& dp){

    if(n<=0) return -1e9;

    if(dp[n] != -1) return dp[n];
    int ans = -1e9;

    if(st.find(n) != st.end()) ans = 1;
    
    for(int i=1;i<=n/2;i++){

        ans = max(ans, fun(i,st,dp) + fun(n-i,st,dp));

        // int l1 =i , l2 = n-i;
        // if(st.find(l1) != st.end() && st.find(l2) != st.end()) {
        //     ans = max(ans,1 + max(fun(i,st,dp),fun(n-i,st,dp)));
        // }
    } 

    return dp[n] = ans;  
}
int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;

    set<int> st;
    st.insert(a);
    st.insert(b);
    st.insert(c);

    vector<int> dp(n+1,-1);
    cout<<fun(n,st,dp)<<endl;

}