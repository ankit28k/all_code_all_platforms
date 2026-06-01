#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    unordered_map<char,int> m;
    for(int i=0;i<n;i++) m[s[i]]++;

    int count =0;
    for(auto i = m.begin() ; i!= m.end();i++){
      if(i->second %2 != 0) count ++;
    }

    if(n==1) cout<<"YES"<<endl;
    else if(count - 1 <= k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
}