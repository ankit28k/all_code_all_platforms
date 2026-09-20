#include<bits/stdc++.h>
using namespace std;

int cidx(vector<vector<long long>>& arr,int val){
    int l=0,h=arr.size()-1,ans=arr.size();
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m][0]>val){
            ans = m;
            h=m-1;
        }
        else l = m+1;

    }
    return ans;
}
long long fun(int idx,int n,vector<vector<long long>>& arr,vector<long long>& dp){
    if(idx>=n) return 0;

    if(dp[idx] != -1) return dp[idx];
    long long nt = fun(idx+1,n,arr,dp);
    int nxtidx = cidx(arr,arr[idx][1]);
    long long t = arr[idx][2] + fun(nxtidx,n,arr,dp);

    return dp[idx] = max(t,nt);
}
int main(){
    int n;
    cin>>n;
    vector<vector<long long>> arr(n);
    for(int i=0;i<n;i++) {
        long long a,b,r;
        cin>>a>>b>>r;
        arr[i] = {a,b,r};  
    }

    sort(arr.begin(),arr.end());
    vector<long long> dp(n,-1);
    cout<<fun(0,n,arr,dp)<<endl;
}