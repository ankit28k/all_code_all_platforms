#include<bits/stdc++.h>
using namespace std;

bool comp(int val,const pair<int,int>& a){
    return val < a.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        int h,l;
        cin>>h>>l;
        arr[i] = {l,h};
    }

    sort(arr.begin(),arr.end());
    vector<int> smax(n);
    smax[n-1] = arr[n-1].second;
    for(int i=n-2;i>=0;i--) smax[i] = max(smax[i+1],arr[i].second);

    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        int idx = upper_bound(arr.begin(),arr.end(),t,comp) - arr.begin();
        if(idx==n) cout<<smax[n-1]<<endl;
        cout<<smax[idx]<<endl;
    }

}