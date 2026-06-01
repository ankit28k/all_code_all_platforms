#include<bits/stdc++.h>
using namespace std;

// int maxdifference(vector<int>& arr,int maxele , int minele ,int n){ 

//   if(n==1) return 0;
//   if(arr[n-1] == maxele || minele == arr[0] || arr[0] == maxele || minele == arr[n-1]) return maxele-minele;
//   else  return max(abs(maxele - arr[0]) , abs(arr[n-1] - minele));

// }

int maxdifference(vector<int>& arr , int n){ 

  if(n==1) return 0;
  int ans = arr[n - 1] - arr[0]; 

  // Case 1: Maximize a_n, keeping a_0 fixed.
  int max_suffix = 0;

  for (int i = 1; i < n; i++) {
    max_suffix = max(max_suffix, arr[i]);
  }
  ans = max(ans, max_suffix - arr[0]);

  // Case 2: Minimize a_0, keeping a_{n-1} fixed.
  int min_prefix = INT_MAX;  
  for (int i = 0; i < n - 1; i++) {
    min_prefix = min(min_prefix, arr[i]);
  }
  ans = max(ans, arr[n - 1] - min_prefix);

  // Case 3: Rotate the whole array.
  // This results in the max difference between circularly adjacent elements.
  for (int i = 0; i < n; i++) {
    ans = max(ans, arr[i] - arr[(i + 1) % n]);
  }

  return ans;

}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    int maxele = INT_MIN , minele = INT_MAX;
    for(int i=0;i<n;i++) {
      cin>>arr[i];
      // maxele = max(maxele,arr[i]);
      // minele = min(minele,arr[i]);
    } 

    //cout<<maxdifference(arr,maxele,minele,n)<<endl;
    cout<<maxdifference(arr,n)<<endl;

  }
}