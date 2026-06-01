#include <bits/stdc++.h>
using namespace std;

// assume range [l,r] has k consecutive integers....dividing the n....
// sice [l,r] has k consecutive integers ....there must be number which is divisible by k .....ex- 456 ...6 is divisible by 3...
// similarly for k-1 ,k-2....1 
// => [1,k] contains elements which divide  all numbers in range [l,r].....which all divide n
// => [1,k] is the length of [l,r]

int main(){
  int t;
  cin>>t;
  while(t--){
    long long n;
    cin>>n;

    int i =1;
    while(n%i == 0) i++;

    cout<<i-1<<endl;
  }
}