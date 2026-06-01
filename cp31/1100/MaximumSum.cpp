#include <bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());

    //You always perform k operations. There are only k+1 possible scenarios:
    // Remove 0 pairs of mins and k maxs.
    // Remove 1 pair of mins and k-1 maxs.
    // Remove 2 pairs of mins and k-2 maxs.
    // ...and so on.
    // Remove k pairs of mins and 0 maxs.

    vector<long long> psum_mins , psum_max;

    psum_mins.push_back(0); //0 pair .. mins
    psum_max.push_back(0); // 0 times max

    long long prev =0;
    for(int i=0;i<k;i++){
      prev += arr[2*i] + arr[2*i+1];
      psum_mins.push_back(prev);
    }

    prev = 0;
    for(int i=n-1;i>= n-k;i--){
      prev += arr[i];
      psum_max.push_back(prev);
    } 

    long long sum = accumulate(arr.begin(),arr.end(),0LL);
    long long ans = LLONG_MIN;

    for(int i=0;i<=k;i++){
      long long curr = sum - psum_mins[i] -  psum_max[k-i] ; 
      ans = max(ans,curr);
    }

    cout<<ans<<endl;
    
    // int i=0,j = n-1;
    // while(k--){
    //   if(arr[i]+arr[i+1] < arr[j]) i=i+2;
    //   else j--;
    // }

    // long long ans=0;
    // for(int l = i;l<=j;l++) ans+=arr[l];
    // cout<<ans<<endl;
  }
}