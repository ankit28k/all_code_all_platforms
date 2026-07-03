#include<bits/stdc++.h>
using namespace std;

class sgt{
    vector<pair<int,pair<int,int>>> seg;
public:
    sgt(int n){
        seg.resize(4*n);
    }

    void build(int idx,int low,int high,vector<int>& arr){
        if(low == high) {
            int val = arr[low];
            seg[idx] = {1,{val,val}};
            return;
        }

        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);

        if(seg[2*idx + 1].second.second <= seg[2*idx+2].second.first) {
            seg[idx].first = seg[2*idx+1].first + seg[2*idx+2].first;
            seg[idx].second = {seg[2*idx+1].second.first , seg[2*idx+2].second.second};
        }

        else{
            
        }

    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        char c;
        cin>>c;
        arr[i] = c-'0';
    }

}