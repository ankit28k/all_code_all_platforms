#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n ;
    long long c;
    cin>>n>>c;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i]; 
    
    for(int i=0;i<n;i++) {
      arr[i] += (i+1);
    }

    sort(arr.begin(),arr.end());

    int ans =0;

    for(int i=0;i<n;i++){
      if(c >= arr[i]) {
        ans++;
        c -= arr[i];
      }

      else break;
    }

    cout<<ans<<endl;
  }
}