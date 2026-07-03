#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int footcfq,int horcfq,int tf,int th,int n1,int n2,int k1,int k2){

    if(idx==n1+n2) return 1;

    if(tf>n1 || th>n2) return 0;

    int ans =0;

    if(tf<n1 && th<n2 && footcfq<k1 && horcfq<k2) ans += fun(idx+1,footcfq+1,0,tf+1,th,n1,n2,k1,k2) + fun(idx+1,0,horcfq+1,tf,th+1,n1,n2,k1,k2);
    else {
        if(footcfq>=k1 && th<n2) ans += fun(idx+1,0,horcfq+1,tf,th+1,n1,n2,k1,k2);
        if(horcfq>=k2 && tf<n1) ans += fun(idx+1,footcfq+1,0,tf+1,th,n1,n2,k1,k2);
    }

    return ans;
}
int main(){
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    cout<<fun(0,0,0,0,0,n1,n2,k1,k2)<<endl;

}