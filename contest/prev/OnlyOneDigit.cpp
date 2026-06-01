#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    int ans = INT_MAX;

    while(n){
      int ld = n%10;
      ans = min(ans,ld);
      n=n/10;
    }

    cout<<ans<<endl;
  }
}