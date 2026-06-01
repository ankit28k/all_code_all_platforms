#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long power(long long a,long long b){

  long long ans =1;
  while(b){
    if(b%2 == 1) {
      ans = (ans*a)%mod;
      b--;
    }

    else{
      a = (a*a) %mod;
      b = b/2;
    }
  }
  return ans;
}
int main(){
  int n;
  cin >> n;
 
  cout<<( power(2,n)%mod )<<endl; 
  
}