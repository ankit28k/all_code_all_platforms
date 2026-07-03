#include<bits/stdc++.h>
using namespace std;

class sgt{
    vector<long long> seg,lazy;
public: 

    sgt(int n){
        seg.resize(4*n,0);
        lazy.resize(4*n,0);
    }
    void build(int idx,int low,int high,vector<long long>& arr){
        if(low == high){
            seg[idx] =arr[low];
            return ;
        }

        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
    }

    long long query(int idx,int low,int high,int i){
        
        if(lazy[idx] != 0){ //update previous
            seg[idx] += lazy[idx]; 

            //propagate downwards
            if(low!= high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }

            lazy[idx]=0;
        }

        if(low==high) return seg[idx];

        int mid = (low+high)/2;
        if (i <=mid)  return query(2*idx+1,low,mid,i);
        else return query(2*idx+2,mid+1,high,i);

    }

    void update_range(int idx,int low,int high,int l,int r,long long val){

        if(lazy[idx] != 0){ //update previous
            seg[idx] += lazy[idx]; 

            //propagate downwards
            if(low!= high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }

            lazy[idx]=0;
        }
        
        //no overlap
        if(high<l || low > r) return ;

        //complete overlap
        if(low>=l && high<=r) {
            seg[idx] += val;
            if(low != high){
                lazy[2*idx+1] += val;
                lazy[2*idx+2] += val;
            }
            return;
        }

        //partial overlap
        int mid = (low+high)/2;
        update_range(2*idx+1,low,mid,l,r,val);
        update_range(2*idx+2,mid+1,high,l,r,val);
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
            int l,r;
            long long val;
            cin>>l>>r>>val;
            l--;r--;
            sg.update_range(0,0,n-1,l,r,val);
        }

        else {
            int i;
            cin>>i;
            i--;
            cout<<sg.query(0,0,n-1,i)<<endl;
        }
    }

}