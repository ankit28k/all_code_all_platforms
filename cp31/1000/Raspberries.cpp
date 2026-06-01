#include <bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int k,int n){
  
  int ans =INT_MAX;
  int zero_cnt =0,one_cnt =0;

  for(int i=0;i<n;i++){
    if(arr[i]%k == 0) return 0;
    ans = min(ans ,k - arr[i]%k);

    if(arr[i]%2==0) zero_cnt++;
    else one_cnt++; 

  }

  if(k!=4 ) return ans;
  else{ 
    if(zero_cnt>=2) return 0;
    else if(zero_cnt==0) return min(ans,2);
    else if(zero_cnt==1) return min(ans,1);
  }

  
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<<fun(arr,k,n)<<endl;
  }
}