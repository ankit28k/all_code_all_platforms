#include<bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int zcnt =0,ocnt=0;
    for(int i=0;i<n;i++){
      if(arr[i]==0) zcnt++;
      if(arr[i]==1) ocnt++;
    }

    long long zero = pow(2,zcnt);
    //int one = fact(ocnt)/fact(ocnt-1)*fact(1) = ocnt
    long long ans = ocnt*zero;  //2^0 as can choose any number of zeroes ...and ....onct that is choose any 1 one to remove
    cout<<ans<<endl;
  }
}