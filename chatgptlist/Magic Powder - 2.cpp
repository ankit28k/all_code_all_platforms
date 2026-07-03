#include<bits/stdc++.h>
using namespace std;

bool poss(long long m,vector<long long>& arr,vector<long long>& brr,long long k){
    long long extra=0,n = arr.size();
    for(int i=0;i<n;i++){
        extra += max(0LL,arr[i]*m - brr[i]);
        if(extra>k) return false;
    }

    return extra<=k;
}
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n),brr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>brr[i];

    long long l = 0,h=0,ans=0;
    for(int i=0;i<n;i++){
        h = max(h,(brr[i]+k)/arr[i]);
    }

    while(l<=h){
        long long m = l + (h-l)/2;
        if(poss(m,arr,brr,k)){
            ans = m;
            l=m+1;
        }
        else h = m-1;
    }
    
    cout<<ans<<endl;
}