#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    bool found = false;
    int a,b,c;

    //only need to check consecutive numbers for a peak....as its a permutation that is no number is same......so it cant be 2 4 4 4 6 7
    for(int k=1;k<n-1;k++){
      if(arr[k]>arr[k-1] && arr[k]>arr[k+1]){
        a=k;
        b=k+1;
        c=k+2;
        found = true;
        break;
      }
    }

    // for(int k=1;k<n;k++){
    //   for(int i=0,j=n-1;i<k && j>k;i++,j-- ){
    //     if(arr[i]<arr[k] && arr[j]<arr[k]){
    //       a=i+1;
    //       b = k+1;
    //       c=j+1;
    //       found = true;
    //       break;
    //     }
    //   }
    //   if(found) break;
    // }

    if(found) {
      cout<<"YES"<<endl;
      cout<<a<<" "<<b<<" "<<c<<" "<<endl;;
    }
    else cout<<"NO"<<endl;
    
  }
}