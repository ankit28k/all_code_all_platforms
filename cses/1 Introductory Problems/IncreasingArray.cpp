#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;

  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  long long count =0;
  for(int i=0;i<n-1;i++){
    if(arr[i]>arr[i+1]) {
      count = count + (arr[i] - arr[i+1]);
      arr[i+1] = arr[i];
    }
  }

  cout<<count<<endl;
}