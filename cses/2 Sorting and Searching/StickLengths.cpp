#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector< long long> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  sort(arr.begin(),arr.end());

  //median is the number we need to add or subtract from every element to get min cost


  long long median = arr[n/2];
  long long cost = 0;
  for(int i=0;i<n;i++){
    cost += abs(arr[i] - median);
  }
  cout<<cost<<endl;
}