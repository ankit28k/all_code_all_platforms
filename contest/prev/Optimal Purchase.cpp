#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,a,b;
        cin>>n>>a>>b;
        
        long long allind = n*a;
        long long mix = (n/3)*b + (n%3)*a;
        long long allg = ((n+2)/3)*b;
        cout<<min({allind,mix,allg})<<endl;

    }

}