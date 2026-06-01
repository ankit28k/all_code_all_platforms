#include <bits/stdc++.h>
using namespace std;

bool isprime(long long n) {
  if (n < 2) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main(){
  int t;
  cin>>t;


  while(t--){
    int d;
    cin>>d;

    //difference is atleast d .....not d....only 2 prime divisor 1 , p1,p2 , p1*p2
    int p1 = 1+d;
    while(!isprime(p1)) p1++;

    int p2 = p1+d;
    while(!isprime(p2)) p2++;

    cout<<p1*p2<<endl;

  }




  // while(t--){
  //   int d;
  //   cin>>d;

  //   int k=3 , temp = 1,ans =1;
  //   while(k--){
  //     temp += d;
  //     ans *= lcm(ans,temp);
  //   }

  //   cout<<ans<<endl;
  // }

}