#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i].first>>arr[i].second;
  }

  sort(arr.begin(),arr.end());

  int count=0;
  for(int i=0,j=1;j<n && i<j;i++){
    if( arr[i].second > arr[j].first){
      count++;
      j++;
    }
  }
}