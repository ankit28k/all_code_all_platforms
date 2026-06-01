#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;

  int n = s.length();

  int count=1 , ans=1;
  for(int i=0;i<n-1;i++){
    if(s[i] == s[i+1]){
      count++;
    }

    else {
      ans = max(ans,count);
      count = 1;

    }
  }

  ans = max(ans, count); // Final update if all are same
  
  cout<<ans<<endl;

}