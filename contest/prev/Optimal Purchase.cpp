#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,a,b;
        cin>>n>>a>>b;
        long long ans=0;
        if(a*3<b) cout<<n*a<<endl;
        else cout<<(n/3)*b + min((n%3)*a , b)<<endl;
        

    }

}