#include <bits/stdc++.h>
using namespace std;

int fun(long long a,long long b){

  if(a==b) return 0;

  long long k ;

  if(a>b){
    if(a % b != 0 ) return -1;  
    k = a/b;
  }
  
  else if(a<b){
    if(b % a != 0 ) return -1;  
    k = b/a;
  }


  // if(a>b){
  //   if((a/b)%2 != 0 ) return -1;
  //   else k = a/b;
  // }
  
  // else if(a<b){
  //   if((b/a)%2 != 0 ) return -1;
  //   else k = b/a;
  // } 

  // check if ratio is power of 2
  if((k & (k-1)) != 0) return -1;
 

  int count =0;

  while(k>1){
    if (k % 8 == 0) k /= 8;
    else if (k % 4 == 0) k /= 4;
    else if (k % 2 == 0) k /= 2;
    count++;
  }

  return count;

}

int main(){
  int t;
  cin>>t;
  while(t--){
    long long a,b;
    cin>>a>>b;
    cout<<fun(a,b)<<endl; 
  }
}