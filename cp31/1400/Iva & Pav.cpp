#include<bits/stdc++.h>
using namespace std;

bool poss(int l,int k,int mid ,int n,vector<vector<int>>& pand){

    int len = mid -l+1;
    int ans =0;
    for(int bit=0;bit<31;bit++){

        int count ;
        if(l>0) count = pand[bit][mid] - pand[bit][l-1];
        else count = pand[bit][mid] - 0;

        if(count == len) ans += pow(2,bit);
    }

    return ans>=k;
}

int bs(int l,int k,int n,vector<vector<int>>& pand){
    
    int low = l,high = n-1 , ans = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(poss(l,k,mid,n,pand)){
            ans = mid;
            low = mid+1;
        }

        else high = mid-1;
    }

    if(ans == -1) return -1;
    return ans+1;

}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<vector<int>> pand(31,vector<int>(n));

        for(int bit = 0;bit<31;bit++) pand[bit][0] = (arr[0]>>bit) & 1;
        
        for(int i=1;i<n;i++){
            for(int bit = 0;bit<31;bit++){

                int cbit = (arr[i]>>bit) & 1;
                pand[bit][i] = pand[bit][i-1] + cbit;
            }
        }

        int q;
        cin>>q;

        vector<int> ans;
        while(q--){
            int l,k;
            cin>>l>>k;
            l--; // 0 based indexing
            
            if(arr[l]<k) ans.push_back(-1);
            else ans.push_back(bs(l,k,n,pand));

        }

        for(int x:ans) cout<<x<<" ";
        cout<<endl;
    }

}