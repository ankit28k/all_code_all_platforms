#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,m,a;
    cin>>n>>m>>a; 
    long long ans = 1LL*((n+a-1)/a) * ((m+a-1)/a) ;
    cout<<ans<<endl;


}