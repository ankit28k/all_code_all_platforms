#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        
        long long k=n%4 , temp = n/4;
        long long ans = temp*7;
        
        if(k==1) ans+=1;
        else if(k==2) ans+=3;
        else if(k==3) ans+=4;

        // long long maxpow2 = log2(n);

        // maxpow2 -=2;
        // if(maxpow2 >0 )ans += maxpow2*(maxpow2+1)/2;

        // ans += n/8;
        // ans += n/16;
        // ans += n/32;

        long long t = 1 , i=3;

        //as multiple of 8 give extra 1, multiple of 16 give extra 1 and so on...so we need to consider only power of 2 greater than 8
        while(t<=n){ 

            t = pow(2,i);
            ans += n/t;
            i++;

        }

        cout<<ans<<endl;
    }

}