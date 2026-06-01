#include <bits/stdc++.h>
using namespace std;

// Answer is 0: If the array consists entirely of zeros, no operations are needed.
// Answer is 1: If all the non-zero elements form a single contiguous block. ...Example: 0 0 2 5 3 0 0
// Answer is 2: If the non-zero elements are separated by zeros (multiple blocks).....Example: 2 0 3

int fun(vector<int>& arr){
  int n = arr.size() , cnt=0;

  for(int i=0;i<n;i++) {
    if(arr[i]!=0 && (i==0 || arr[i-1]==0)) cnt++;
  }
  
  if(cnt==0) return 0;
  else if(cnt==1 ) return 1;
  else return 2;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<<fun(arr)<<endl;

  }
}