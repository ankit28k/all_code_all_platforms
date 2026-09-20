#include<bits/stdc++.h>
using namespace std;

long long poss(long long x,long long d){

    return x + ((d+x)/(x+1));
}

string fun(long long n,long long d){
    if(d<=n) return "YES";

    long long l=0,h=d,ans=d;
    while(l<=h){
        long long m = l+(h-l)/2;
        long long temp = poss(m,d);

        ans = min(ans,temp);
        if(temp<=poss(m+1,d)) h=m-1;
        else l = m+1;
    }

    if(ans<=n) return "YES";
    else return "NO";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        cout<<fun(n,d)<<endl;
    }

}