#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int ew=0,ow=0;
        
        bool ve1=true;
        for(int i=0;i<n;i+=2) {
            char exp = ((i/2)%2 ==0) ?'0':'1';
            if(s[i]!= '?' && s[i] != exp) ve1 =false;
        }
        if(ve1) ew++;

        bool ve2 = true;
        for(int i=0;i<n;i+=2) {
            char exp = ((i/2)%2==0)?'1':'0';
            if(s[i]!= '?' && s[i]!=exp) ve2 =false;
        }
        if(ve2) ew++;

        bool vo1 = true;
        for(int i=1;i<n;i+=2) {
            char exp = ((i/2)%2==0) ?'0':'1';
            if(s[i]!= '?' && s[i] != exp) vo1 =false;
        }
        if(vo1) ow++;

        bool vo2 = true;
        for(int i=1;i<n;i+=2) {
            char exp =((i/2)%2==0) ? '1':'0';
            if(s[i]!= '?' && s[i]!=exp) vo2=false;
        }
        if(vo2) ow++;

        cout<<(1LL*ew*ow)%998244353<<endl;
    }
}