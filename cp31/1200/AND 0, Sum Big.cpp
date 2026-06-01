#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 +7;

long long fun(int n,int k){ 

    //long long maxsum = (pow(2,k) - 1)*(n-1)*1LL;
    //long long ans =0;

    //case 1...where array is ....1 0 and rest are 2^k -1
    //ans += n; // 0 can be at any position i.e n....

    //case 2.....where array is like 
    // 01111 
    // 10111 
    // 11011 
    // 11101 
    // 11110
    // its possible as its summation = 2^k - 1....hence fact of n as all are different number

    // long long factn = 1;
    // for(int i=2;i<=n;i++) factn = (factn*i)%mod;
    // ans = (ans + factn)%mod;

    //general case.....where array is like 
    // 01111  or 0011  
    // 10111     1111
    // 11011     1100
    // 11101     1111
    // 11110
    // its possible as its summation = 2^k - 1....hence choose any row in every column...to make it 0 ....so for evry column i have n choices nc1
    // to make it 0...since we can make any row column 0 ...no need of case 1 too....and choose the elements generated
    
    long long temp =1;
    for(int i=1;i<=k;i++) {
        temp  = (temp*n) % mod ;
    } 
    
    return temp;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;   
        cout<<fun(n,k)<<endl;
    }

}