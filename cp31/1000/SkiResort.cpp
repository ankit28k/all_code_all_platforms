#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    int n,k;
    long long q;
    cin>>n>>k>>q;

    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n;i++){
      if(arr[i]>q) arr[i]=0;
      else arr[i] =1;
    }

    long long temp=0 , sum=0;
    for(int i=0;i<n;i++){

      if(arr[i]==1) temp++;

      else{
        if(temp>=k) sum+= 1LL*((temp-k+1)*(temp-k+2)/2); // no of possible subaarays formula.....
        temp =0;
      }
    }

    if(temp>=k) sum+= 1LL*((temp-k+1)*(temp-k+2)/2);

    cout<<sum<<endl;
  }
}