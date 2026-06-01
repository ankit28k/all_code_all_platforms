#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long> arr(n),brr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];

        vector<long long> psum(n) , maxi(n);
        psum[0] =arr[0];
        maxi[0] = brr[0];


        for(int i=1;i<n;i++) {
            psum[i] = psum[i-1]+arr[i];
            maxi[i] = max(maxi[i-1],brr[i]);
        }

        long long ans= 0;

        for(int i=0;i<n;i++){

            if(i >= k) break;
            long long temp = psum[i] + (k- (i+1))*maxi[i];
            ans = max(ans,temp);
        }

        cout<<ans<<endl;
    }

}