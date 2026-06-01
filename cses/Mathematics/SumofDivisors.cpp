#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){ 
  
  int n;
  cin>>n;

  int ans=0;

  for(int i=1 ;i*i <=n;i++){
    if(n%i == 0) {
      if(n%i == 0 && i==n/i)  ans = (ans + i)%mod;
      else ans = (ans + i + n/i ) % mod;
    }
  }

  cout<<ans%mod<<endl;

  
}