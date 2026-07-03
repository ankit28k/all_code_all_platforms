#include<bits/stdc++.h>
using namespace std;

int main(){ 
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<long long> psum(n+1,0);
        
        vector<pair<int,int>> queries;
        while(q--){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            queries.push_back({l,r});
            psum[l]++;
            psum[r+1]--;

        }

        for(int i=1;i<=n;i++) psum[i] += psum[i-1];
        map<int,long long> mp;
        for(int i=0;i<n;i++) mp[i] = psum[i];
        
        vector<pair<long long,int>> temp;
        for(auto it:mp){
            temp.push_back({it.second,it.first});
        }

        sort(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());

        vector<int> temparr(n);

        for(int i=0;i<n;i++){
            int idx = temp[i].second;
            temparr[idx] = arr[i];
        }

        long long ans = 0;
        for(int i=0;i<n;i++){
            int fq = mp[i];
            ans += 1LL*fq*temparr[i];
        }

        cout<<ans<<endl;

    

}