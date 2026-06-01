#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        int val = arr[i] - (i+1);
        mp[val].push_back(arr[i]);
    }

    long long ans =0;
    for(auto it:mp){
        long long sum = accumulate(it.second.begin(),it.second.end(),0LL);
        ans = max(ans,sum);
    }

    cout<<ans<<endl;
}