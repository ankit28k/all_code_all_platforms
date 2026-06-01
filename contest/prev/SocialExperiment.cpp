#include<bits/stdc++.h>
using namespace std;

int fun(int n){
  if(n==2 || n==3) return n;
  if(n%2==0) return 0;
  if(n%2 != 0) return 1;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<fun(n)<<endl;
  }
}