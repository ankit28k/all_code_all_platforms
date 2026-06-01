#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){

  if(b==0) return a;
  
  return gcd(b,a%b);
}

int main(){
  int t;
  cin>>t;
  
  while(t--){
    int n;
    cin>>n;
 
    int ans =0;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      ans = gcd(ans,abs(x-1-i));
    }

    cout<<ans<<endl;
  }
}