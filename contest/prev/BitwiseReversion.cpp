#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int x, y,z;
    cin>>x>>y>>z;

    int k = x&y&z;
    if((x&y) == k && (x&z)==k && (y&z) ==k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    
  }
}