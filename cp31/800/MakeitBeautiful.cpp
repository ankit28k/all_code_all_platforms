
#include <bits/stdc++.h>
using namespace std;

bool isUgly(const vector<int>& arr) {

  int sum = 0;
  for (int i =0;i<arr.size();i++) {
    if (arr[i] == sum) return true;
    sum += arr[i];
  }
  return false;
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

    // If all elements are equal → impossible
    if(arr[0] == arr[n-1]) {
      cout<<"NO"<<endl;
      continue;
    }
    // Try largest first, rest ascending
    vector<int> res;
    res.push_back(arr[n - 1]);
    for (int i = 0; i < n - 1; i++) res.push_back(arr[i]);

    // If still ugly, find first element smaller than largest and move it to the front
    if (isUgly(res)) {
      for (int i = 1; i < n; i++) {
        if (res[i] != res[0]) {
          swap(res[0], res[i]);
          break;
        }
      }
    }
    
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<endl;
  }
}

// int n;
// cin>>n;
// vector<int> arr(n);
// for(int i=0;i<n;i++) cin>>arr[i];

// int sum=0;
// bool check = false;
// for(int i=0;i<n;i++){
//   if(arr[i] == sum) {
//     check = true;
//     swap(arr[i],arr[i-1]);
//   }
//   else sum+=arr[i];
// }

// if(check) {
//   cout<<"YES"<<endl;
//   for(int i=0;i<n;i++) cout<<arr[i]<<" ";
// } 

// else cout<<"NO"<<endl;
