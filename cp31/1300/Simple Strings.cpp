#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;

    int n = s.length();  
    for(int i=0;i<n-2;i++){

        if(s[i]==s[i+1] && s[i+1]==s[i+2]){ 
            s[i+1] = (char)((s[i+1] - 'a' + 1)%26 + 'a');
        }
    }

    for(int i=0;i<n-1;i++){

        if(s[i]==s[i+1]){ 
            if(i==0)  s[i] = (char)((s[i] - 'a' + 1)%26 + 'a');
            else{

                char l = (char)((s[i] - 'a' + 1)%26 + 'a');
                if(s[i-1] == l) l = (char)((l - 'a' + 1)%26 + 'a');
                s[i] = l;
            }
        }
    }

    cout<<s<<endl;

}