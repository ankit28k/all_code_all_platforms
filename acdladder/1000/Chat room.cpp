#include<bits/stdc++.h>
using namespace std;
int main(){
    
    string s;
    cin>>s;

    string ans="";
    string hello = "hello";

    int n = s.length();

    int i=0,j=0;
    while(i<n){
        if(s[i] == hello[j]) {
            i++;
            j++;
            continue;
        }
        else {
            s[i]='?';
            i++;
        }
    }

    
    for(int i=0;i<n;i++){
        if(s[i] != '?') ans.push_back(s[i]);
    }

    if(ans==hello) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}