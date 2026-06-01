#include <bits/stdc++.h>
using namespace std;
int makecount(vector<int> &arr,int n){

  int ans =0;
  for (int i = n - 2; i >= 0; i--) {

    while (arr[i] >= arr[i + 1] && arr[i] > 0) {
      arr[i] /= 2;
      ans++;
    }

    if (arr[i] >= arr[i + 1]) return -1; // impossible case
  }
  

  return ans;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<<makecount(arr,n)<<endl;
  }
}