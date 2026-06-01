#include<bits/stdc++.h>
using namespace std;


int fun(vector<int>& arr,int n){

  if(n==1) return 0;
  int maxfreq =1  , temp =1;

  for(int i=0;i<n-1;i++){

    if(arr[i]==arr[i+1]){
      temp++;
      maxfreq = max(maxfreq,temp);
    }

    else temp =1;
  }

  if(maxfreq == n) return 0;

  int swaps = n - maxfreq; //need exactly this many swaps 
  int clone = 0;

  // cloning double our capacity.....do until we cover n
  while(maxfreq < n){
    clone++;
    maxfreq *= 2;
  }
  
  // int toReplace = n-maxfreq;

  // int swaps = toReplace;
  // int clone =1;
  // if(maxfreq >= toReplace) return clone + swaps;

  // while(maxfreq < toReplace){
  //   maxfreq = maxfreq*2;
  //   clone++;
  // }

  return swaps + clone;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());

    cout<<fun(arr,n)<<endl;
  }
}