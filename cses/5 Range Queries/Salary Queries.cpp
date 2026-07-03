#include<bits/stdc++.h>
using namespace std;

class sgt{
    vector<int> seg;
public:
    sgt(int n){
        seg.resize(4*n);
    }

    void build(int idx,int low,int high,vector<int>& arr){
        if(low== high){
            seg[idx] = arr[low];
            return ;
        }

        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
    }

    int query(int idx,int low,int high,int l,int r){

        if(low>r || high<l) return 0; //no

        if(low>=l && high<=r) return high-low+1; //complete
        else{//partial
            int mid = (low+high)/2;
            int left = query(2*idx+1,low,mid,l,r);
            int right = query(2*idx+2,mid+1,high,l,r);
            return left + right;
        }
    }
    void update(int idx,int low,int high,int i,int val){
        if(low == high){
            seg[idx] = val;
            return;
        }

        int mid = (low+high)/2;
        if(i<=mid) update(2*idx+1,low,mid,i,val);
        else update(2*idx+2,mid+1,high,i,val);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
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
        char t;
        cin>>t;
        if(t=='!'){
            int i,val;
            cin>>i>>val;
            i--;
            sg.update(0,0,n-1,i,val);
        } 

        else{
            int l,r;
            cin>>l>>r;
            cout<<sg.query(0,0,n-1,l,r)<<endl;
        }
    }

}