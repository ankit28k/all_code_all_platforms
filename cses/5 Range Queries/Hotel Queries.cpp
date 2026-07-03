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

        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
    }

    int query(int idx,int low,int high,int val){

        if(seg[idx] < val ) return -1;

        if(low == high){
            return low;
        }
        
        int mid = (low+high)/2;
        int left ,right;
        left = query(2*idx+1,low,mid,val);
        if(left != -1) return left;
        else return right = query(2*idx+2,mid+1,high,val);
    
    }

    void update(int idx,int low,int high,int i,int val){
        if(low == high){
            seg[idx] -= val;
            return;
        }

        int mid = (low+high)/2;
        if(i <= mid) update(2*idx+1,low,mid,i,val);
        else update(2*idx+2,mid+1,high,i,val);

        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n), que(q);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<q;i++) cin>>que[i];

    sgt sg(n);
    sg.build(0,0,n-1,arr);
    vector<int>ans(q);

    for(int i=0;i<q;i++){
        int idx = sg.query(0,0,n-1,que[i]);
        if(idx != -1){
            sg.update(0,0,n-1,idx,que[i]);
            ans[i] = idx+1;
        }
        else ans[i]=0;
        
    }

    for(int x:ans) cout<<x<<" ";
    cout<<endl;

}