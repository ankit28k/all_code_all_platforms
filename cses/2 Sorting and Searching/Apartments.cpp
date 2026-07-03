#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    while(m--){
        int val;
        cin>>val;
        int mxval = val+k , mnval = val-k;

        auto itmin = lower_bound(arr.begin(),arr.end() ,mnval);
        auto itmx = upper_bound(arr.begin(),arr.end() ,mxval);
    } 


}