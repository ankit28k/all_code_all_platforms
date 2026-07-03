#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> dp(n,1);
    vector<long long> cnt(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]) {

                if(dp[i]<1 +dp[j]) {
                    dp[i] = 1+dp[j];
                    cnt[i] = cnt[j];
                }

                else if(dp[i] == 1 + dp[j]) cnt[i] = (cnt[i] + cnt[j])%mod; 
            }
        }
    }
    
    map<int,long long> mp;
    for(int i=n-1;i>=0;i--){
        if(dp[i]>1 && mp.find(dp[i]) == mp.end()) mp[dp[i]] = cnt[i];
    }
    long long ans=n;
    for(auto it:mp) ans = (ans + it.second)%mod;
    cout<<ans<<endl;

    

}