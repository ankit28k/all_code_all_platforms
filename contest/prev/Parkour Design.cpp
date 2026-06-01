#include<bits/stdc++.h>
using namespace std;

string fun(long long x,long long y){

    if(y==0){
        if(x%3==0) return "YES";
        return "NO";
    }

    else if(y>0){
        long long k = 2*y;
        if(k>x) return "NO";
        if(k==x || abs(k-x) %3 ==0) return "YES";
        return "NO";

    }

    else if(y<0){
        long long k = 4* abs(y);
        if(k>x) return "NO";
        if(k==x || abs(k-x) %3 ==0) return "YES";
        return "NO";
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        cout<<fun(x,y)<<endl;
    }

}