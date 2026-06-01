#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            arr[i] = {x,i} ;
        }

        sort(arr.begin(),arr.end());

        vector<pair<long long,int>> psum(n) , cnt(n);

        psum[0] = {arr[0].first , arr[0].second};

        for(int i=1;i<n;i++) psum[i] = {psum[i-1].first+arr[i].first , arr[i].second};

        cnt[n-1] ={n-1,psum[n-1].second};

        for(int i=n-2;i>=0;i--){
            if(psum[i].first >= arr[i+1].first) cnt[i] = {cnt[i+1].first,psum[i].second};
            else cnt[i] = {i,psum[i].second};
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int idx = cnt[i].second;
            int ele = cnt[i].first;
            ans[idx] = ele;
        }

        for(int x:ans) cout<<x<<" ";
        cout<<endl;
    }

}