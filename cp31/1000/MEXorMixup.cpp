#include<bits/stdc++.h>
using namespace std;

int fun(int a,int b){

    //TLE
    // int zor =0;
    // for(int i=0;i<a;i++) zor = zor^i;

    int zor;
    if((a-1)%4 == 0) zor = a-1;
    if((a-1)%4 == 1) zor = 1;
    if((a-1)%4 == 2) zor = a; //a-1 + 1
    if((a-1)%4 == 3) zor = 0;

    if(zor==b) return a;
    if((zor^b )!= a) return a+1;
    else return a+2;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        
        cout<<fun(a,b)<<endl;
        
    }

}