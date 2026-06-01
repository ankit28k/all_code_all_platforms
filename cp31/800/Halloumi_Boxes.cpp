#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    bool ans = true;
    for(int i=0;i<n;i++) cin>>arr[i]; 
 
    if(k>=2) cout<<"YES"<<endl;
    if(k==1){
      for(int i=1;i<n;i++)  {
        if(arr[i]<arr[i-1]) ans = false;
      }

      if(ans) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    

  }
}