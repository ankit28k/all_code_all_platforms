#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){

    int n , k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int count = 0 , ans =0 , i=0;
    while(i<n){

      if(arr[i] == 0 ){
        count++; 
        i++;

        if(count == k){
          count = 0;
          ans++;
          i++;
        }
      } 

      else if(arr[i] == 1) {
        count = 0;
        i++;
      }
 

    }

    cout<<ans<<endl;
  }
}