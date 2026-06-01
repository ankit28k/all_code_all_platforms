#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    int ans =INT_MIN;
    for(int i=0;i<n;i++) cin>>arr[i];
    
    for(int i=0;i<n;i++) {
      ans = max(ans,arr[i]);
    }
    cout<<ans*n<<endl;
  }
  
}