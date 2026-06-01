#include <bits/stdc++.h>
using namespace std;


bool fun(vector<int>& arr){
  int zcnt = 0,onecnt =0 , n = arr.size();

  for(int i=0;i<n;i++){
    if(arr[i]==0) zcnt++;
    if(arr[i]==1) onecnt++;
  }

  if(zcnt==1) return true;
  else if( zcnt>1 && onecnt ==1) return true ;
  else return false;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    if(fun(arr)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}