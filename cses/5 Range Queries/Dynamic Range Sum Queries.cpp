#include<bits/stdc++.h>
using namespace std;


class sgt{
    vector<long long> seg;
public: 

    sgt(int n){
        seg.resize(4*n);
    }
    void build(int idx,int low,int high,vector<long long>& arr){
        if(low == high){
            seg[idx] =arr[low];
            return ;
        }

        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    long long query(int idx,int low,int high,int l,int r){
        //no overlap
        if(low > r || high <l ) return 0;

        //complete overlap
        if(l<=low && r>=high) return seg[idx];

        else{
            int mid = (low+high)/2;
            long long left = query(2*idx+1,low,mid,l,r);
            long long right = query(2*idx+2,mid+1,high,l,r);

            return left+right;
        }

    }

    void update(int idx,int low,int high,int i,int val){
        if(low == high){
            seg[idx] = val;
            return;
        }

        int mid = (low+high)/2;
        if(i <= mid) update(2*idx+1,low,mid,i,val);
        else update(2*idx+2,mid+1,high,i,val);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
};


int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sgt sg(n);
    sg.build(0,0,n-1,arr);

    while(q--){
        int t;
        cin>>t;

        if(t==1){
            int i,val;
            cin>>i>>val;
            i--;
            sg.update(0,0,n-1,i,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout<<sg.query(0,0,n-1,l,r)<<endl;
        }
    }


}