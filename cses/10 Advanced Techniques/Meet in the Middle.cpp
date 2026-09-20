#include <bits/stdc++.h>
using namespace std;

long long fun(int n, long long x, vector<long long>& arr) {
    
    int n1 = n/2;
    int n2 = n-n1;

    vector<long long> suma(1LL<<n1);
    for(auto mask = 0 ;mask<(1LL<<n1);mask++){
        long long sum=0;
        for(int i=0;i<n1;i++){
            if((mask>>i)&1) sum+=arr[i];
        }

        suma[mask] = sum;
    }
    vector<long long> sumb(1LL<<n2);
    for(auto mask = 0 ;mask<(1LL<<n2);mask++){
        long long sum=0;
        for(int i=0;i<n2;i++){
            if((mask>>i)&1) sum+=arr[n1+i];
        }

        sumb[mask] = sum;
    }

    sort(sumb.begin(),sumb.end());
    long long ans=0;
    for(int i=0;i<(1LL<<n1);i++) {
        if(suma[i] >x) continue;
        long long rem = x - suma[i];
        
        int lbidx = lower_bound(sumb.begin(),sumb.end(),rem) - sumb.begin();
        int ubidx = upper_bound(sumb.begin(),sumb.end(),rem) - sumb.begin();
        
        ans += ubidx-lbidx;
    }
    return ans;
}

int main() {
    
    int n; 
    long long x;
    cin>>n>>x;

    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<fun(n,x,arr)<<endl;
}
