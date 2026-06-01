#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int sum = n+1;
    vector<int> ans(n); 
    for(int i=0;i<n;i++){
      ans[i] = sum-arr[i];
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;

  }
}