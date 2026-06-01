#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;

    long long sum =a;
    while(a){
        int left  = a; 

        if(left >= b){
            sum+= (left/b);
            a= a/b + a%b;
        }
        else break;
        
    }

    cout<<sum<<endl;

}