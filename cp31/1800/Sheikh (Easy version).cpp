#include<bits/stdc++.h>
using namespace std;


int bsl(int l,int r,vector<long long>& psum,vector<long long>& pzor, long long mxval){

    int low = l,high = r,bestl=l;

    while(low<=high){
        int mid = low+(high-low)/2;

        long long midval =  (psum[r]-psum[mid-1]) - (pzor[r]^pzor[mid-1]);
        if(midval>=mxval) {
            bestl = mid;
            low = mid+1;
        }
        else high = mid-1;
    }

    return bestl;
}

int bsr(int l,int r,vector<long long>& psum,vector<long long>& pzor, long long mxval){

    int low = l,high = r,bestr=r;

    while(low<=high){
        int mid = low+(high-low)/2;

        long long midval =  (psum[mid]-psum[l-1]) - (pzor[mid]^pzor[l-1]);
        if(midval>=mxval) {
            bestr = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return bestr;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<long long> psum(n+1) , pzor(n+1);
        for(int i=1;i<=n;i++) {
            psum[i] = psum[i-1]+arr[i-1];
            pzor[i] = pzor[i-1]^arr[i-1];
        }


        while(q--){
            int l,r;
            cin>>l>>r;
            if(l==r) {
                cout<<l<<" "<<r<<endl;
                continue;
            }

            long long mxval = (psum[r]-psum[l-1]) - (pzor[r]^pzor[l-1]);
            int bestl = bsl(l,r,psum,pzor,mxval);
            int bestr = bsr(l,r,psum,pzor,mxval);

            cout<<bestl<<" "<<bestr<<endl;
            
        }
        
    }

}