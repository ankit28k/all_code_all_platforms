#include<bits/stdc++.h>
using namespace std;


int fun(string s){

    int n = s.length(), zcnt=0,ocnt=0;
    if(n==1) return 1;

    for(int i=0;i<n;i++){
        if(s[i]=='0') zcnt++;
        else ocnt++;
    }

    if(zcnt==ocnt) return 0;

    for(int i=0;i<n;i++){

        if(s[i]=='0'){
            if(ocnt>0) ocnt--;
            else return n-i;
        }
        else {
            if(zcnt>0) zcnt--;
            else return n-i;
        }
    }

    // for(int i=0;i<n;i++){ //mine

    //     if(s[i]=='0')ocnt--;
    //     else zcnt--;
        
    //     if(ocnt<=0 || zcnt<=0) return n-1 -i;
    // }
    return -1;
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