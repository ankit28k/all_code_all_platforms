#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 +7;

int main(){
  int t;
  cin>>t;
  while(t--){
    long long n;
    cin>>n;

    // vector of size 1e9 is not possible.....hence use formula....= sum(i^2) + sum( i(i-1) 
    //=> n(n+1)(2n+1) /6 (i^2) +  n(n+1)(2n+1) /6 (i^2) - n(n+1)/2 .....i^2 + i^2 +i

    // 2*i^2 - i ...=> n(n+1)(2n+1)/3 - n(n+1)/2 ....=> n(n+1)(4n-1)/6
    // multiply by 2022 => (n(n+1)(4n-1)/6) *2022 .....=> n(n+1)(4n-1) * 337  as 2022/6 =337 

    long long ans = (n*(n+1))%mod; 
    ans = (ans*(4*n-1))%mod; 
    ans = (ans* 337)%mod; 
    cout<<ans<<endl;

    // vector<vector<int>> arr(n+1,vector<int>(n+1));

    // long long sum=0; 

    // for(int i=1;i<=n;i++){  ..... = sum(i^2) + sum( i(i-1)).....move right -> down ...right-> down...then see in reverse
    //   int j=i;
    //   sum+= i*j; //i*i
    //   sum+= i*(j-1); i*i-1;
    // }

    // int ans = (sum*2022)%mod;
    // cout<<ans<<endl;
  }
}