#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> minmax(long long n){
  if(n%2 != 0 || n<4) return {-1,-1};
  if(n==4 || n==6) return {1,1};  
  
  return {(n+5)/6,n/4};
  //return {ceil(n/6),n/4};
} 

int main(){
  int t;
  cin>>t;
  while(t--){
    long long n;
    cin>>n; 
    pair<long long,long long> ans = minmax(n);
    if(ans.first == -1) cout<<-1<<endl;
    else cout<<ans.first<<" "<<ans.second<<endl;
  }
}