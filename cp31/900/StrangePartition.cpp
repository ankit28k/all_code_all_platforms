#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    long long x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    long long sum = 0 , maxb = 0;

    for(int i=0;i<n;i++){
      sum+=arr[i];
      maxb += (arr[i]+x-1)/x;
     // maxb = ceil(arr[i]/x);
    }

    long long minb =  (sum+x-1)/x;

    cout<<minb<<" "<<maxb<<endl;
  }
}