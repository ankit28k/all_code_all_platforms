#include<bits/stdc++.h>
using namespace std;

long long fun(int x,int y,int a,int b){

    if(a==0 || b==0) return 0;
    if(x==0 && y==0) return 0;

    int mini = min(x,y);

    long long cost = min( 1LL*mini*b + 1LL*abs(x-y)*a, 1LL*a*(x+y));
    return cost;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,a,b;
        cin>>x>>y>>a>>b; 
        cout<<fun(x,y,a,b)<<endl;
    }

}  