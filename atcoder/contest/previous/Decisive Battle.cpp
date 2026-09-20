#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;

    int ecnt=0,wcnt=0;
    for(auto c:s){
        if(c=='E') ecnt++;
        else wcnt++;
    }
    if(ecnt>wcnt) cout<<"East"<<endl;
    else if(wcnt>ecnt) cout<<"West"<<endl;
    else cout<<"Tie"<<endl;

}