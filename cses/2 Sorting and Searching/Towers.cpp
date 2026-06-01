#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;

  
  vector<int> pos(n+1);

  for(int i=0;i<n;i++) {
    int val;
    cin>>val;
    pos[val] = i;
  }

  int count=1;

  for(int i=n;i>=2;i--){
    if(pos[i] > pos[i-1]) count++;
  }

  cout<<count<<endl;
}