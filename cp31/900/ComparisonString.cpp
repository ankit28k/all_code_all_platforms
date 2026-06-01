#include <bits/stdc++.h>
using namespace std;

int findmax(vector<char>& arr,char k,int n){
  int count = 0 , ans =0 ;
  for(int i=0;i<n;i++){
    if(arr[i] == k) {
      count++;
      ans = max(ans,count);
    }

    else count =0;
  }
  return ans;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<char> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int count = 1; 
    count += max(findmax(arr,'>',n) , findmax(arr,'<',n));
    cout<<count<<endl;
  }
}