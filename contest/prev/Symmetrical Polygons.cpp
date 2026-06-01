 
#include <bits/stdc++.h>
using namespace std;


long long fun(vector<long long>& arr , unordered_map<long long,int>&  m , int n){  
   
  long long perimeter = 0;

  vector<long long> odd ;  

  for(auto i=m.begin();i!=m.end();i++){

    if((i->second)%2==0){
      perimeter += (i->first * i->second);
    }  

    else { 
      odd.push_back(i->first);
      i->second -= 1;
       
      perimeter += (i->first * i->second);

    }
  } 

 
  //if ((n - odd.size()) <=2) return 0;

  sort(odd.begin(), odd.end());

  if (odd.size() == 0) return perimeter;
  else{
    auto it = lower_bound(odd.begin(), odd.end(), perimeter); // it gives iterati]or
    int idx = it - odd.begin() - 1;// idx = it - even.begin() ....gives index
    if(idx<0) return 0;
    if (odd.size() == 1) {

      perimeter += odd[idx];
    }

    if (odd.size() >=2) {

      perimeter += (odd[idx] + odd[idx-1]) ;
    } 
  }  
  return perimeter;
    
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<long long> arr(n);

    unordered_map<long long,int> m;
    for(int i=0;i<n;i++) {
      cin>>arr[i];
      m[arr[i]]++; 
    } 
    
    cout<<fun(arr,m,n)<<endl;

  }
} 