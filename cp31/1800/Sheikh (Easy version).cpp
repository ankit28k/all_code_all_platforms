#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<int> psum(n) , pzor(n);
        psum[0] = arr[0];
        pzor[0] = arr[0];
        for(int i=1;i<n;i++) {
            psum[i] = psum[i-1]+arr[i];
            pzor[i] = pzor[i-1]^arr[i];
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            if(l==r) {
                cout<<l<<" "<<r<<endl;
                continue;
            }

            l--;
            r--;
            
        }
        
    }

}