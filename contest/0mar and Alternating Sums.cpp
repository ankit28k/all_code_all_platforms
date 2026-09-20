#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long pwr(long long b,long long e){
    long long ans=1;
    b = b%mod;
    while(e>0){
        if(e%2==1) ans = (ans*b)%mod;
        b = (b*b)%mod;
        e /=2;
    }

    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<long long,long long>> arr;

        long long ncnt=0,k=0;
        for(int i=0;i<n;i++) {
            long long x;
            cin>>x;

            if(x<0) ncnt++;
            else{
                if(arr.empty() || arr.back().first != x) arr.push_back({x,1});
                else arr.back().second++;
            }
        }

        int nt = arr.size();
        for(int i=1;i<nt;i++){
            if(arr[i].first == arr[i-1].first+1) k++;
        }

        long long w = 1,c0=1,c1=0;
        for(auto it:arr){
            w = (w*pwr(2,it.second-1))%mod;
        }

        if(ncnt>0){
            c0=pwr(2,ncnt-1);
            c1 =c0;
        }

        long long ans= (c0*w)%mod;
        long long temp = ((c1*k)%mod * w)%mod;

        ans = (ans+temp)%mod;
        cout<<ans<<"\n";

    }

}