#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin>>n;

  vector<long long> ans;

  while(n != 1){

    ans.push_back(n);

    if(n % 2 == 0) n=n/2;
    else n = 3 *n + 1;
    
  }

  ans.push_back(1);

  for(long long val: ans) cout<<val<<" ";
  cout<<endl;
}