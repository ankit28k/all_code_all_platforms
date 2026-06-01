#include<bits/stdc++.h>
using namespace std;

int fun(string& s,int n){

  for(int i=0;i<n-1;i++){
    if(s[i] > s[i+1]) return i;
  }

  return -1;
}

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;

  int k = fun(s,n);
  if(k == -1) cout<<"NO"<<endl;
  else{
    cout<<"YES"<<endl;
    cout<<k+1<<" "<<k+2<<endl; // 1 based indexing
  }
  

}