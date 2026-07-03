#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    int x,y;
    cin>>x>>y;

    int hcf = gcd(x,y);
    x = x/hcf;
    y = y/hcf;
    if(x==16 || y==9) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}