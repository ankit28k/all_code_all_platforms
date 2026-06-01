#include<bits/stdc++.h>
using namespace std;

bool check_pal(string s){
    int n = s.length();
    for(int i=0,j=n-1;i<j;i++,j--){
        if(s[i] =='?' || s[j]=='?') continue;
        if(s[i] != s[j]) return false;
    }

    return true;
}

bool alt(string s){
    int n = s.length();

    for(int i=0;i<n-1;i++){
        if(s[i]=='?') continue;
        if(s[i]==s[i+1]) return false;
    }

    return true;
} 
string fun(string& s,int n){
    
    bool fcheck = s[n-1]=='a' && s[n-2]=='b' || s[n-1]=='b' && s[n-2]=='a' || s[n-1]=='a' && s[n-2]=='?' || s[n-1]=='?' && s[n-2]=='a' ||
    s[n-1]=='b' && s[n-2]=='?' || s[n-1]=='?' && s[n-2]=='b';

    if(!fcheck) return "NO";
    s.pop_back();
    s.pop_back();


    if(n%2 == 0 && (alt(s) | check_pal(s))) return "YES";
    else if(n%2 != 0 ){
        if( alt(s) | (s[0]=='a' && s[s.length()-1]=='a')) return "YES";
    }
    else  return "NO";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<fun(s,n)<<endl;

    }

}