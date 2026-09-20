#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        map<int,int> mp;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            mp[arr[i]]++;
        }
        sort(arr.begin(),arr.end());

        int ans=0;
        int maxi = arr[n-1];
        for(int i=1;i<=maxi;i++){
            int temp = mp[i] + mp[2*i];
            int idx = upper_bound(arr.begin() ,arr.end(),i) - arr.begin();
            temp += n-idx;

            ans = max(ans,temp);

        }
        cout<<ans<<endl;
    }

}