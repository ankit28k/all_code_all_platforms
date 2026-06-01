#include<bits/stdc++.h>
using namespace std;

// make a frequency map of second string.....and start from last ....and check if we use that character in second string or not....i.e m[c]>0...
//from last as we remove the first occurence of that character
//if it not there in second string....make it any single character like . / ? ...i.e all become same except the second string in first string
//ex - DETERMINED TRME .....?? T ? RM ?? E ? 

int main(){
  int n;
  cin>>n;
  while(n--){
    string s,t;
    cin>>s>>t;
    
    int m = s.length() , n = t.length();
    unordered_map<char,int> f_map;
    for(int i=0;i<n;i++) f_map[t[i]]++;

    for(int i=m-1 ; i>=0;i--){
      if( f_map[s[i]] >0) f_map[ s[i]]--;
      else{
        s[i] = '?';
      }
    }
    
    string ans = "";
    for(int i=0;i<m;i++){
      if(s[i] != '?') ans.push_back(s[i]);
    }

    if(ans == t) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
}