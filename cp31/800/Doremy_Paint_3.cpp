#include <bits/stdc++.h>
using namespace std;

string doremypaint(vector<int> &arr,int n){
  int var1 = arr[0] , var1f = 1,var2 = -1,var2f = 0;
  for(int i=1;i<n;i++){
    if(arr[i] != var1 && var2==-1){
      var2 = arr[i];
      var2f++;
    }

    else if(arr[i] != var1 && arr[i] != var2) return "NO";
    else if(arr[i]==var1) var1f++;
    else if(arr[i]==var2) var2f++;
  }

  if(var1f == 0 || var2f ==0) return "YES";
  return abs(var1f - var2f)<=1 ? "YES" : "NO";
}
   
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout<<doremypaint(arr,n)<<endl;
    
  }
}