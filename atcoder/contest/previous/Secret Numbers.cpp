#include<bits/stdc++.h>
using namespace std;
int main(){
    string s , ans="";
    cin>>s;

    for(int i=0;i<s.length();i++){
        if(s[i]<='9' && s[i]>='0') ans.push_back(s[i]);
    }

    cout<<ans<<endl;

}