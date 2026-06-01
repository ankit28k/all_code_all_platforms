#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0;i<n;i++) cin>>arr[i];

  stack<int> s;
  vector<int> ans(n);

  for(int i=0;i<n;i++){
    while(s.size()>0 && arr[s.top()]>= arr[i]) s.pop();

    if(s.empty()) ans[i]=0;

    else ans[i] = s.top()+1;
    s.push(i);

  }

  for(int i=0;i<n;i++) cout<<ans[i]<<" ";
}