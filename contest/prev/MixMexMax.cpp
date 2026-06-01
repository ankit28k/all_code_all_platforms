#include<bits/stdc++.h>
using namespace std;

string mixmax(vector<int> &arr, int n) {
  int t_val = -1;
  bool t_found = false;

  for (int x : arr) {
    if (x != -1) {
        if (!t_found) {
          t_val = x;
          t_found = true;
        } 
        
        else {
          if (x != t_val)  return "NO";
            
        }
    }
  }

  if (!t_found)  return "YES";
  

  if (t_val == 0)  return "NO";
   
  return "YES";
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << mixmax(arr, n) << endl;
  }
}