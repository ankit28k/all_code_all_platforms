#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int l=0,r=0;
    long long ans=0;
    map<int,int> mp;
    while(r<n){

        mp[arr[r]]++;

        while(l<=r && (int)mp.size()>k){
            if(mp[arr[l]]>1) mp[arr[l]]--;
            else mp.erase(arr[l]);
            l++;
        }

        ans += r-l+1;
        r++;
    }

    cout<<ans<<endl;

}