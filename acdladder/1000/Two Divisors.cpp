#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

long long fun(int a,int b){
    
    if(a==1) return b*b;
    int hcf = gcd(a,b);
    long long lcm = (1LL*a*b)/hcf;
    if(lcm==b) return a*b;
    else return lcm;
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