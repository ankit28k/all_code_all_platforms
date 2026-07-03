#include<bits/stdc++.h>
using namespace std;

long long fun(int idx,vector<long long>& fq,vector<long long>& dp){
    if(idx>=fq.size()) return 0;

    if(dp[idx] != -1) return dp[idx];

    long long t= fq[idx]*idx + fun(idx+2,fq,dp);
    long long nt=fun(idx+1,fq,dp);
    
    return dp[idx] = max(t,nt);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int maxi=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }

    vector<long long> fq(maxi+1,0);
    for(int i=0;i<n;i++){
        fq[arr[i]]++;
    }

    vector<long long> dp(maxi+1,-1);
    cout<<fun(1,fq,dp)<<endl;
    

}