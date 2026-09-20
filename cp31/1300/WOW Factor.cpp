#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length() ;
    
    vector<long long> pr(n,0),sf(n,0);

    int temp=0,lidx=-1,cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='v') temp++;
        else {
            temp=0;
            lidx = i;
        }
        if(temp==0 && i>0) pr[i]=pr[i-1];
        else{
            pr[i] = max(0,temp-1);
            if(lidx != -1) pr[i] += pr[lidx];
        }
    }
    
    temp=0;
    lidx =-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='v') temp++;
        else {
            temp=0;
            lidx = i;
        }
        if(temp==0 && i<n-1) sf[i]=sf[i+1];
        else{
            sf[i] = max(0,temp-1);
            if(lidx != -1) sf[i] += sf[lidx];
        }
    }
    
    long long ans=0;
    for(int i=1;i<n-1;i++){
        if(s[i]=='o') ans += pr[i-1]*sf[i+1];
    }
    cout<<ans<<endl;

}