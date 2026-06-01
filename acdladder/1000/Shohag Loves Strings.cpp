#include<bits/stdc++.h>
using namespace std;


string fun(string& s){
    int n = s.length(); 

    if(n==1) return "-1";

    if(n==2){
        if(s[0]==s[1]) return s;
    } 

    for(int i=0;i<n-1;i++){

        if(s[i]==s[i+1]) {
            string temp = "";
            // temp = s[i]+s[i+1];
            temp = string(1, s[i]) + s[i+1];
            return temp;
        }

        if(i<=n-3){
            if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i]!=s[i+2]) {
                string temp = "";
                // temp = s[i]+s[i+1] +s[i+2];
                temp = string(1, s[i]) + s[i+1] + s[i+2];
                return temp;
            }
        }
        
    }

    return "-1";
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<fun(s)<<endl;
        
    }

}