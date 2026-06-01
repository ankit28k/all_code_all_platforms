#include <bits/stdc++.h>
using namespace std;


int main(){
   
  int n ,d;
  cin>>n>>d;

  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  sort(arr.begin(),arr.end());

  int i=0,j=n-1 , cnt=0;
  while(i<=j){

    int req = d/ arr[j] ;

    if(i+req <=j){
      i+=req;
      j--;
      cnt++;
    }
    else break;
  }

  cout<<cnt<<endl;

  
}