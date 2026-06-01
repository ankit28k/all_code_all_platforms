// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//   }
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());

    int temp = 1,ans =1;

    for(int i=0;i<n-1;i++){
      
      if(arr[i]==arr[i+1])continue;
      if(arr[i] + 1 == arr[i+1] ) temp++;
      else {
        ans = max(ans,temp);
        temp=1;
      }
    }
    ans = max(ans,temp);
    cout<<ans<<endl;
  }
}