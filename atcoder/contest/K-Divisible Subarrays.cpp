#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr[i] = x%k;
    }

    map<long long,long long> mp;
    mp[0]=0;

    long long sum=0 ,ans=0;
    for(int i=0;i<n;i++){
        sum = (sum + arr[i])%k;
        
        if(mp.find(sum) != mp.end()) ans = max(ans,mp[sum]+1);
        mp[sum] = ans;
        
    }

    cout<<ans<<endl;

}