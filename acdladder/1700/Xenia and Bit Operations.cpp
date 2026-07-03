#include<bits/stdc++.h>
using namespace std;

class sgt{
    vector<int> seg;
public:
    sgt(int n){
        seg.resize(4*n);
    }

    void build(int idx,int low,int high,vector<int>& arr,bool fzor){
        if(low == high){
            seg[idx] = arr[low];
            return;
        }

        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr,!fzor);
        build(2*idx+2,mid+1,high,arr,!fzor);

        if(fzor) seg[idx] = seg[2*idx+1]^seg[2*idx+2];
        else seg[idx] = seg[2*idx+1]| seg[2*idx+2];
    }

    void update(int idx,int low,int high,int i,int val,bool fzor){

        if(low==high){
            seg[idx] = val;
            return;
        }

        int mid = (low+high)/2;
        if(i<=mid) update(2*idx+1,low,mid,i,val,!fzor);
        else update(2*idx+2,mid+1,high,i,val,!fzor);

        if(fzor) seg[idx] = seg[2*idx+1]^seg[2*idx+2];
        else seg[idx] = seg[2*idx+1]| seg[2*idx+2];
    }
    int query(){
        return seg[0];
    }
};
int main(){

    int n,m;
    cin>>n>>m;

    int as = pow(2,n);
    vector<int> arr(as);
    for(int i=0;i<as;i++) cin>>arr[i];
    
    sgt sg(as);
    bool fzor = true;
    if(n%2 == 0) sg.build(0,0,as-1,arr,fzor); //if n is even first zor 
    else sg.build(0,0,as-1,arr,!fzor);

    while(m--){
        int i, val;
        cin>>i>>val;
        i--;
        if(n%2==0) sg.update(0,0,as-1,i,val,fzor);
        else sg.update(0,0,as-1,i,val,!fzor);

        cout<<sg.query()<<endl;
    }

    

}

