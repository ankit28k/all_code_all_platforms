#include<bits/stdc++.h>
using namespace std;

bool ispossible(int a,int b,int c,int d){
  return (d-c+a-b)>=0 && d>=b;
}

int main(){
  int t;
  cin>>t;
  while (t--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(ispossible(a,b,c,d)) cout<<(a-c + d-b + d-b)<<endl; //up-> d-b ....then d-b left to same x....then a-c to desired x (left only)
    else cout<<-1<<endl;

  }
  
}