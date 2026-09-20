#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<long long> fact(16) , pow2(41);
    fact[0]=1;
    for(int i=1;i<=15;i++){
        fact[i] = fact[i-1]*i;
    }
    for(int i=0;i<=40;i++){
        pow2[i] = 1LL<<i;
    }

    vector<pair<long long,long long>> suma;
    for(int mask=0;mask<=(1LL<<15);mask++){
        long long sum=0,cnt=0;
        for(int i=0;i<=15;i++){
            if((mask>>i)&1) sum+=fact[i];
        }
        suma.push_back({sum,cnt});
    }

    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        for(int mask=0;mask<(1LL<<15);mask++){
            
            long long req = n - suma[mask].first;
            int idx = lower_bound(pow2.begin(),pow2.end(),req)-pow2.begin();
            if(pow2[idx]==req){

            }
            if(n<suma[mask].first) break;
        }
    }

}