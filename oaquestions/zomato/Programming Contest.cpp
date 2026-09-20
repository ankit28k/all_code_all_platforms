#include <bits/stdc++.h>
using namespace std;

long long maxQuantity(int n, long long maxt, vector<long long>& arr) {
    
    int n1 = n/2;
    int n2 = n-n1;

    vector<long long> suma(1LL<<n1);
    for(auto mask = 0 ;mask<(1LL<<n1);mask++){
        long long sum=0;
        for(int i=0;i<n1;i++){
            if((mask>>i)&1) sum += arr[i];
        }

        suma[mask] = sum;
    }
    vector<long long> sumb(1LL<<n2);
    for(auto mask = 0 ;mask<(1LL<<n2);mask++){
        long long sum=0;
        for(int i=0;i<n2;i++){
            if((mask>>i)&1) sum+= arr[n1+i];
        }

        sumb[mask] = sum;
    }

    sort(sumb.begin(),sumb.end());
    long long ans=0;
    for(int i=0;i<(1LL<<n1);i++) {
        if(suma[i] >maxt) continue;

        long long rem = maxt - suma[i];

        int idx = upper_bound(sumb.begin(),sumb.end(),rem) - sumb.begin();
        
        if(idx>0) ans = max(ans,suma[i] + sumb[idx-1]);
    }
    return ans;
    
}

int main() {
    
    int n; 
    long long maxt;
    cin>>n>>maxt;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    cout << maxQuantity(n,maxt,arr) << "\n";
    return 0;
}
