#include<bits/stdc++.h>
using namespace std;

class sgt{
    vector<int> seg;
public: 

    sgt(int n){
        seg.resize(4*n);
    }
    void build(int idx,int low,int high,vector<int>& arr){
        if(low == high){
            seg[idx] =arr[low];
            return ;
        }

        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);

        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }

    int query(int idx,int low,int high,int l,int r){
        //no overlap
        if(low > r || high <l ) return INT_MAX;

        //complete overlap
        if(l<=low && r>=high) return seg[idx];

        else{
            int mid = (low+high)/2;
            int left = query(2*idx+1,low,mid,l,r);
            int right = query(2*idx+2,mid+1,high,l,r);

            return min(left,right);
        }

    }
};

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sgt sg(n);
    sg.build(0,0,n-1,arr);

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int ans  = sg.query(0,0,n-1,l,r);
        cout<<ans<<endl;
    }

}