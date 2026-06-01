#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    set<pair<int,int>> st;
    map<int,int> mp;

    vector<int> ans;
    int l=0,r=0;
    for(;r<k;r++){
        mp[arr[r]]++;
        st.insert({mp[arr[r]] , arr[r]});
    }

    auto mode = *(st.rbegin());
    ans.push_back(mode.second);

    while(r<n){
        mp[arr[r]]++;
        st.insert({mp[arr[r]] , arr[r]});
        st.erase({mp[arr[l]],arr[l]});

        mp[arr[l]]--;


        r++;
        l++;

        auto mode = *(st.rbegin());
        ans.push_back(mode.second);
    }

    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}