#include<bits/stdc++.h>
using namespace std;

int main(){ 

    int n,m;
    cin>>n>>m;

    map<string,string> mp;
    for(int i=0;i<m;i++){
        string x,y;
        cin>>x>>y;
        mp[x] =y;
    }

    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<string> ans(n);
    for(int i=0;i<n;i++){
        int l1 =arr[i].length() , l2 = mp[arr[i]].length();
        if(l1<=l2) ans[i] = arr[i];
        else ans[i] = mp[arr[i]];
    }

    for(auto x:ans) cout<<x<<" ";
    cout<<endl;

    

}