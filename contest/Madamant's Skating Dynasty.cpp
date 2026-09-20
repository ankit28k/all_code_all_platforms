#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
long long power(long long b, long long e){
    long long ans = 1;
    b =b%mod;
    while (e>0) {
        if(e%2 ==1) ans = (ans*b)%mod;
        b = (b*b)%mod;
        e /= 2;
    }
    return ans;
}

long long modinv(long long n) {
    return power(n,mod-2);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        if(n==1){
            cout<<0<<endl;
            continue;
        }

        sort(arr.begin(),arr.end());
        vector<long long> sf(n);

        sf[n-1] = arr[n-1]%mod;
        for(int i=n-2;i>=0;i--){
            sf[i] = (sf[i+1]+arr[i])%mod;
        }

        long long fact= 1;
        for(int i=1;i<n;i++) fact = (fact*i)%mod;

        long long ans=0;
        for(int i=0;i<n-1;i++){
            long long cnt = (fact*modinv(n-1-i))%mod;
            long long val = (cnt*sf[i+1])%mod;
            long long temp = (fact*(arr[i]%mod))%mod;
            ans = (ans+val-temp + mod)%mod;
        }

        cout<<ans<<endl;
    }

}