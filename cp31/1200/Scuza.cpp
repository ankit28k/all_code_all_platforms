#include<bits/stdc++.h>
using namespace std;

bool compareFirst(int val, const pair<int, int>& p) {
    return val < p.first;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr(n),qrr(q);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<q;i++) cin>>qrr[i];

        vector<long long> psum(n);
        psum[0] = arr[0];
        for(int i=1;i<n;i++) psum[i] = psum[i-1]+arr[i];
        
        int maxi = 0;
        vector<pair<int,int>> temp;
        
        for(int i=0;i<n;i++){ 
            if(arr[i]>maxi) {
                temp.push_back({arr[i],i});
                maxi = max(arr[i],maxi);
            }
        }
         
        sort(temp.begin(),temp.end());
        int nt = temp.size();

        vector<long long> ans(q);
        for(int i=0;i<q;i++){
            int lessthanequal = upper_bound(temp.begin(),temp.end(),qrr[i], compareFirst) - temp.begin(); 

            if(lessthanequal==nt){
                ans[i] = psum[n-1];
            }
            else if(lessthanequal>0 ){
                int idxreq = temp[lessthanequal].second -1 ;
                ans[i] = psum[idxreq];
            }
            else ans[i]=0;
        }

        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }

}