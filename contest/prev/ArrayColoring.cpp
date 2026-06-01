#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n) ,sorted;
    for(int i=0;i<n;i++) cin>>arr[i];

    unordered_map<int,bool> m;

    sorted = arr;
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
      m[sorted[i]] = i%2;
    }
    // for(int i=0;i<n;i=i+2){
    //   m[arr[i]] = false;
    //   m[arr[i+1]] = true;
    // }

    bool flag =true;
   

    for(int i=0;i<n-1;i++){
      if((m[arr[i]] == m[arr[i+1]]) ) {
        flag = false;
        break;
      }
      
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}