#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n; 

    int ans  = 0;

    for(int i=0;i<n;i++){
      int x;
      cin>>x; 
      ans = ans^x;
    }

    if (n % 2 == 0) {
      if (ans == 0) cout << 0 << endl; // any x works
      else cout << -1 << endl;
    } 
    else  cout << ans << endl; // x = xorSum
    


  }
}