#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    vector<char> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int mxcount =0 ,count1 =0 , count2=0;
    for(int i=0;i<n;i++){
      if(arr[i]=='.'){
        count1++;
        count2++;
        mxcount = max(mxcount,count1);
      }
      
      else count1 =0;
    }  

    if(mxcount>=3) cout<<2<<endl;
    else cout<<count2<<endl;
  }
  
}
