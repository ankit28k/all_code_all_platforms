#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<long long> psum(n+1);

    psum[0] =0;
    psum[1] = arr[0];
    for(int i=2;i<=n;i++) psum[i] = psum[i-1] + arr[i-1];
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<psum[r]- psum[l-1]<<endl;
    }

}