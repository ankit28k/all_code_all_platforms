#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  while(n--){
    int a, b;
    cin >> a >> b;
    if(a>0 && b>0){
      if((a + b)%3 == 0) cout<<"YES"<< endl;
      else cout<<"NO"<< endl;
    }

    else cout<<"NO"<< endl;
    
  }
}
