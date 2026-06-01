#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr(n),brr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];

        int maxi =0;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,brr[i]);
            if(maxi>arr[i]) {
                arr[i]=maxi;
            }
        }

        int maxi2 = 0;
        for(int i=n-1;i>=0;i--){
            maxi2 = max(maxi2,arr[i]);
            if(arr[i]<maxi2) arr[i] = maxi2;
            
        }
        
        vector<long long> psum(n);
        psum[0] = arr[0];
        for(int i=1;i<n;i++) psum[i] = psum[i-1]+arr[i];

        while(q--){
            int l,r;
            cin>>l>>r;
            l--;
            r--; // for 0 based indexing
            if(l==0) cout<<psum[r]<<" ";
            else cout<<psum[r]-psum[l-1]<<" ";
        }
        cout<<endl;

    }

}