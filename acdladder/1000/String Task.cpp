#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;

    set<char> vow = {'a','e','i','o','u','A','E','I','O','U','Y','y'};

    int n = s.length();
    string ans ="";

    for(int i=0;i<n;i++){
        if(vow.find(s[i]) != vow.end()) continue;
        else{
            ans.push_back('.');
            int k = s[i];
            if(k<=90) k+=32;
            char c = (char)k;
            ans.push_back(c);
        }
    }

    cout<<ans<<endl;
 


}