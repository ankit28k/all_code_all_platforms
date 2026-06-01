#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    map<long long,long long> mp;
    vector<long long>ans;

    int r=0,l=0;
    for(;r<k;r++) mp[arr[r]]++;

    ans.push_back(mp.size());
    while(r<n){
        
        mp[arr[r]]++;

        if(mp[arr[l]]>1) mp[arr[l]]--;
        else mp.erase(arr[l]);

        r++;
        l++;
        ans.push_back(mp.size());
    }
    for(int x:ans)cout<<x<<" ";
    cout<<endl;
}