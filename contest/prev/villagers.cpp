#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());
    long long ecount =0;
    for(int i=n-1;i>=0;i=i-2) ecount+=arr[i];


    cout<<ecount<<endl;
 
  }

  


}