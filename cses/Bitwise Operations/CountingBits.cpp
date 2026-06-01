#include <bits/stdc++.h>
using namespace std;

int onebits(int n){

  int count = 0;

  while(n){
    count += n%2;
    n=n/2;
  }

  return count;
}

int main(){
  int n;
  cin>>n;

  int ans = 0;
  for(int i=1;i<=n;i++) ans += onebits(i);
  cout<<ans<<endl;
}