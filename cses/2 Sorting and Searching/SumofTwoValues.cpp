#include<bits/stdc++.h>
using namespace std;

 
pair<int,int> fun(vector<pair<int,int>>& arr,int n,int x){

  for(int i=0 , j=n-1 ;i<j;){
    int sum = arr[i].first + arr[j].first;
    if( sum == x) return {arr[i].second,arr[j].second};
    else if(sum>x) j--;
    else i++;
  }

  return {-1,-1};
}
int main(){
  int n ,x;
  cin>>n>>x;

  vector<pair<int,int>> arr(n);

  for(int i=0;i<n;i++) {
    cin>>arr[i].first;
    arr[i].second = i+1;
  }
  
  sort(arr.begin(),arr.end());
  pair<int,int> ans = fun(arr,n,x);

  if(ans.first == -1) cout<<"IMPOSSIBLE"<<endl;
  else cout << ans.first << " " << ans.second << endl;
}