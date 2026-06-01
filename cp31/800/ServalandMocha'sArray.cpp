#include<bits/stdc++.h>
using namespace std;

// gcd(a1,a2....ai) <=i -> good
// beautiful -> if all good and length >=2

//  => gcd(a1,a2)<=2
//  => gcd(a1,a2,a3)<=3
//  ...
//  => gcd(a1,a2,...ai)<=i

//  => gcd(a1,a2,...ai)<=gcd(a1,a2) ...if new number added the gcd is same or less never more

//  => gcd(a1,a2)<=2  if any a1,a2 satisfy the its true for all as ...gcd(a1,a2,...ai)<=i....gcd(a1,a2,...ai)<= gcd(a1,a2) <=2....i.e 2<=i for i>2...its always true......
//  => find a pair with gcd <=2 and replace with first and second element

int gcd(int a,int b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    bool flag = false;

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(gcd(arr[i],arr[j]) <= 2) {
          flag= true;
          break;
        }
      }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}