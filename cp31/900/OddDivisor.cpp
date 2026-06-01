#include <bits/stdc++.h>
using namespace std; 

bool checkdivisor(long long n){
  while(n%2==0) n/=2;
  if(n>1) return true;
  else return false;
}

int main()
{
  int t;
  cin>>t;
  while(t--){
    long long n;
    cin>>n;
    if(checkdivisor(n)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;

  } 

}


// bool checkdivisor(int n){
//   for(int i=2;i<=n;i++) {
//     if(n%i==0 && i%2!=0) return true;
//    }
//   return false;
// }
// int main()
// {
//   int t;
//   cin>>t;
//   while(t--){
//     int n;
//     cin>>n;
//     if(checkdivisor(n)) cout<<"yes"<<endl;
//     else cout<<"no"<<endl;

//   } 

// }