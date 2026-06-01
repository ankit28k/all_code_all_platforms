#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    int count=0;

    for(int i=1 ;i*i <=n;i++){
      if(n%i == 0) {
        if(n%i == 0 && i==n/i)  count++;
        else count+=2;
      }
    }

    cout<<count<<endl;

  }
}