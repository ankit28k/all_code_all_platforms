#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> arr(n) ;
    vector<pair<long long,long long>> temp;
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int mask=0;mask< (1LL<<n);mask++){
        long long sum=0;
        for(int i=0;i<n;i++){
            if((mask>>i)&1) sum+=arr[i];
        }
        if(sum<=x) temp.push_back({mask,sum});
    }

    long long val = (1LL<<n) -1;

}