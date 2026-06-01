#include<bits/stdc++.h>
using namespace std;

bool fun(int n,int k){

    long long sum=0;
    while(n){
        int k=n%10;
        sum+=k;
        n=n/10;

    }

    return sum==k;

}
int main(){
    int n,k;
    cin>>n>>k;

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(fun(i,k)) cnt++;
    }

    cout<<cnt<<endl;



}