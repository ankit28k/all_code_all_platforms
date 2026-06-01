#include<bits/stdc++.h>
using namespace std;


//fails when the string has exactly one '0', but the length n is greater than 1 (for example, "11011").
string fun(string s,int n){

    // if(n==1){
    //     if(s[0]=='1') return "DRAW";
    //     else return "BOB"; 
    // }

    //added
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') cnt++;
    }

    if(cnt==1) return "BOB";
    if(cnt==0) return "DRAW";


    if(n%2 != 0 && s[n/2]=='0') return "ALICE";
    else return "BOB" ;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;

        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='0') cnt++;
        // }

        // if(cnt%4==0) cout<<"DRAW"<<endl;

        cout<<fun(s,n)<<endl;
        
        
    }

}