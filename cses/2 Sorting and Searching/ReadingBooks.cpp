#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) cin>>arr[i];

  sort(arr.begin(),arr.end());

  int sum1=0 , sum2=0;
  for(int i=0,j=n-1;i<j;){
     
    if(sum1 > sum2) {
      sum2 += arr[j];
      j--;
    }
    else {
      sum1 += arr[i];
      i++;
    }
  }

  cout<< 2 * (max(sum1,sum2)) <<endl;
}