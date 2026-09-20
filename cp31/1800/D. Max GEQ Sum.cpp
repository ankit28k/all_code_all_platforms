#include<bits/stdc++.h>
using namespace std;

class sgt{
    vector<long long> sgm;
public:
    sgt(int n){
        sgm.resize(4*n);
    }

    void build(int idx,int low,int high,vector<long long>& arr){

        if(low==high){
            sgm[idx]=arr[low];
            return;
        }

        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);

        sgm[idx] = max(sgm[2*idx+1] , sgm[2*idx+2]);

    }

    long long query(int idx,int low,int high,int l,int r){
        
        if(l>high || r<low) return LLONG_MIN;

        if(l<=low && r>=high) return sgm[idx];

        long long mid = (low+high)/2;
        long long left = query(2*idx+1,low,mid,l,r);
        long long right = query(2*idx+2,mid+1,high,l,r);
        return max(left,right);

    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sgt sg(n);
        sg.build(0,0,n-1,arr);
        
        int l=0,r=0,ans=1;
        long long sum=0;
        while(r<n){

            sum+=arr[r];
            while(l<=r && sum<=sg.query(0,0,n-1,l,r)){
                sum-=arr[l];
                l++;
            }

            ans = max(ans,r-l+1);
            r++;
        }

        if(ans>1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

}