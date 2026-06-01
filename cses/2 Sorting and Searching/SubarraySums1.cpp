#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n,x;
  cin >> n >> x;
  vector<int> arr(n);
  vector<long long> prefixsum(n);

  for(int i=0;i<n;i++) cin>>arr[i];

  prefixsum[0] = arr[0];
  unordered_map<long long,long long> m;

  m[prefixsum[0]]++;
  for(int i=1;i<n;i++) {
    prefixsum[i] = prefixsum[i-1] + arr[i];
    m[prefixsum[i]]++;
  }

  long long count =0;
  for(int i=0;i<n;i++) {

    if(prefixsum[i] == x) {
      count++;
      continue;
    }

   
    long long second = prefixsum[i] - x;
    if(m.find(second) != m.end()) count+= m [second];
    
    
  }

  cout<<count<<endl;
 
} 
