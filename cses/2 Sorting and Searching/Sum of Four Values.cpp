#include<bits/stdc++.h>
using namespace std;

pair<int,int> fun2(vector<pair<int,int>>& arr,int n,int x,int idx1,int idx2){

  for(int i=0 , j=n-1 ;i<j;){

    if(i==idx1 ||i==idx2 || j==idx1 || j==idx2){
        if(i==idx1 ||i==idx2 ) i++;
        else if(j==idx1 || j==idx2) j--;
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

pair<int ,pair<int,int>> fun3(vector<pair<int,int>>& arr,int n,int x,int idx){
    for(int i=0;i<n;i++){
        if(i==idx) continue;
        pair<int,int> ans = fun2(arr,n,x-arr[i].first,i,idx);
        if(ans.first != -1) return {arr[i].second,{ans.first,ans.second}};
    }
    return {-1,{-1,-1}};
}

pair<pair<int,int> ,pair<int,int>> fun4(vector<pair<int,int>>& arr,int n,int x){
    for(int i=0;i<n;i++){
        pair<int ,pair<int,int>> ans = fun3(arr,n,x-arr[i].first,i);
        if(ans.first != -1) return {{arr[i].second,ans.first},{ans.second.first ,ans.second.second}};
    }
    return {{-1,-1},{-1,-1}};
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
  pair<pair<int,int> ,pair<int,int>> ans = fun4(arr,n,x);

  if(ans.first.first == -1) cout<<"IMPOSSIBLE"<<endl;
  else cout << ans.first.first<<" "<<ans.first.second << " " << ans.second.first<<" "<<ans.second.second << endl;
}