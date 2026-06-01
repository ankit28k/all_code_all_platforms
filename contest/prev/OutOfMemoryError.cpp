#include <bits/stdc++.h>
using namespace std;

//instead of temp = arr .....subtract all the operation of that index to last crashed index

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m,h;
    cin>>n>>m>>h;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    vector<vector<int>> op(m,vector<int>(2));
    for(int i=0;i<m;i++){
      cin>>op[i][0]>>op[i][1];
    }
    // vector<int> temp = arr;
 
    // for(int i=0;i<m;i++){
    //   int b = op[i][0] - 1  , c =op[i][1];
    //   int og = temp[b];
    //   if (og + c >h) {
    //     temp = arr;
    //     continue;
    //   }
    //   else temp[b] +=c;
 
    // }
 
    // for(int i=0;i<n;i++) cout<<temp[i]<<" ";
    // cout<<endl;

    int lastidx = -1;

    for(int i=0;i<m;i++){
      int b = op[i][0] - 1  , c =op[i][1];
      
      if (arr[b] + c >h) {

        for(int j=i-1;j>lastidx;j--){

          int b = op[j][0] - 1  , c =op[j][1];
          arr[b]-=c;
        }

        lastidx = i;

      }

      else arr[b] +=c;
 
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
  }
  
}