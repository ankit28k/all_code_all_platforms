#include<bits/stdc++.h>
using namespace std;

string func(vector<int>&  arr , int k){

  for(int i=0;i<arr.size();i++){
    if(arr[i]==k) return "YES";    
  }

  return "NO";
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    unordered_map<int,int> m;

    for(int i=0;i<n;i++) cin>>arr[i];
       
    cout<<func(arr,k)<<endl; 
  }
}