#include<bits/stdc++.h>
using namespace std;

long long gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,x,y;
        cin>>n>>x>>y; 

        long long lcmxy = x*y/gcd(x,y);

        
        long long pos = n/x , neg = n/y , common = n/lcmxy;
        long long newpos = pos - common , newneg = neg - common;

        long long psum = newpos*( 2*n + (newpos-1)*(-1))/2; // n/2(2a + (n-1) *d)  ...a =n ,d = -1

        long long nsum= newneg*(2 + (newneg-1))/2; // a =1 , d = 1

        cout<<psum-nsum<<endl;


    }

}