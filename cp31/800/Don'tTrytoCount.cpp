#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    string s,x;
    cin>>x>>s;

    if (x.find(s) != string::npos) {
      cout << 0 << endl;
      continue;
    }

    int count =0;
    while(count <= 4 ){ //n <= m.... mine 

      x=(x+x);
      n*=2;
      
      count++;
      if(x.find(s) != string::npos) break;
      
    }

    if(x.find(s) != string::npos) cout<<count<<endl;
    else cout<<-1<<endl;
  }
}