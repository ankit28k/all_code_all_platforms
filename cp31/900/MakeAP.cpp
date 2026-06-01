#include<bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;

  while(t--){
    int a,b,c;
    cin>>a>>b>>c;
    if(a+c > 2*b){
      if( (a+c) % (2*b) == 0 ) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }

    else if(a+c < 2*b){
      if( (2*b - c) % a == 0  || (2*b - a) % c == 0 ) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }


    else cout<<"YES"<<endl;
  }
}