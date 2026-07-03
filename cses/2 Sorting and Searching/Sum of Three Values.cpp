#include<bits/stdc++.h>
using namespace std;

pair<int,int> fun2(vector<pair<int,int>>& arr,int n,int x,int idx){

  for(int i=0 , j=n-1 ;i<j;){

    if(i==idx || j==idx){
        if(i==idx) i++;
        else if(j==idx) j--;
    }

    else{
        int sum = arr[i].first + arr[j].first;
        if( sum == x) return {arr[i].second,arr[j].second};
        else if(sum>x) j--;
        else i++;
    }
    
  }

  return {-1,-1};
}

pair<int ,pair<int,int>> fun3(vector<pair<int,int>>& arr,int n,int x){
    for(int i=0;i<n;i++){
        pair<int,int> ans = fun2(arr,n,x-arr[i].first,i);
        if(ans.first != -1) return {arr[i].second,{ans.first,ans.second}};
    }
    return {-1,{-1,-1}};
}
int main(){
  int n ,x;
  cin>>n>>x;

  vector<pair<int,int>> arr(n);

  for(int i=0;i<n;i++) {
    int val;
    cin>>val;
    arr[i] = {val,i+1};
  }
  
  sort(arr.begin(),arr.end());
  pair<int ,pair<int,int>> ans = fun3(arr,n,x);

  if(ans.first == -1) cout<<"IMPOSSIBLE"<<endl;
  else cout << ans.first << " " << ans.second.first<<" "<<ans.second.second << endl;
}