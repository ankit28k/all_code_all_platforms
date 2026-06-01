#include <bits/stdc++.h>
using namespace std;

//put the smallest number in array b and rest in array c.....so b has only 1 element and not divisible by any larger element in c

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> b,c;
    sort(arr.begin(),arr.end());

    int k= arr[0];
    for(int i=0;i<n;i++){
      if(arr[i]==k) b.push_back(arr[i]);
      else c.push_back(arr[i]);
    }

    if(b.size() ==0 || c.size()==0) {
      cout<<-1<<endl;
    }

    else{
      cout<<b.size()<<" "<<c.size()<<endl;
      for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
      cout<<endl;
      for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
      cout<<endl;
    }
  }
}