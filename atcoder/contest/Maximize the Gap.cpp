#include<bits/stdc++.h>
using namespace std;

bool poss(long long m,int n,int k,vector<pair<int,int>>& arr){
    int cnt=0;
    long long lr = -1e9;
    for(int i=0;i<n;i++){
        if(arr[i].second >= lr +m){
            cnt++;
            lr = arr[i].first;
        }
    }

    return cnt>=k;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        int l,r;
        cin>>l>>r;
        arr[i] = {r,l};
    }

    sort(arr.begin(),arr.end());
    long long l=1,h=1e9,ans=-1;
    while(l<=h){
        long long m = l + (h-l)/2;
        if(poss(m,n,k,arr)){
            ans = m;
            l = m+1;
        }
        else h = m-1;
    }

    cout<<ans<<endl;

}