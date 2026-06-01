#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k,x;
  cin>>n>>k>>x;

  vector<int> arr(n) , psum(n);
  int tsum =0;

  for(int i=0;i<n;i++) {
    cin>>arr[i];
    tsum += arr[i];
  }
  
  sort(arr.begin(),arr.end());

  psum[0] = arr[0];
  for(int i=1;i<n;i++){
    psum[i] = psum[i-1] + arr[i];
  }
}