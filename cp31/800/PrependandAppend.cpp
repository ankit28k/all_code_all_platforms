#include <bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int l = s.length();
    for(int i=0, j = n-1 ;i<j;){
      if( s[i] - '0' ^  s[j] - '0' == 1) {
        l = l-2;
        i++;
        j--;
      }
      else break;
    }

    cout<<l<<endl;
  }
}