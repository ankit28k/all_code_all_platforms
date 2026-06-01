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

    int count=0;
    int i=0;

    while(i < (int)arr.size() - 1){    // //  vector becomes 1 element shorter after each such operation......erase and insert
    
      if((arr[i]%2==0 && arr[i+1]%2!=0) || (arr[i]%2!=0 && arr[i+1]%2==0)) i++;
      else {
        int prod = arr[i]*arr[i+1];

        arr.erase(arr.begin()+i, arr.begin()+i+2);
        
        arr.insert(arr.begin() +i, prod);    

        count++; 
      }

    }

    cout<<count<<endl;
  }

  
}