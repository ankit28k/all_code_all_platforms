#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int n1 =n/2;
    int n2 = n-n1;
    vector<long long> suma,sumb;

    for(int mask = 0;mask<(1LL<<n1);mask++){
        long long sum=0;
        for(int i=0;i<n1;i++){
            if((mask>>i)&1){
                sum= (sum+ arr[i])%m;
            }
        }
        suma.push_back(sum);
    }

    for(int mask = 0;mask<(1LL<<n2);mask++){
        int sum=0;
        for(int i=0;i<n2;i++){
            if((mask>>i)&1){
                sum= (sum+arr[i+n1])%m;
            }
        }
        sumb.push_back(sum);
    }

    sort(sumb.begin(),sumb.end());

    long long ans=0;
    for(int i=0;i<(1<<n1);i++){

        ans = max(ans,suma[i]);
        int req = m-suma[i];
        int idx = lower_bound(sumb.begin(),sumb.end(),req)-sumb.begin();
        idx--;

        if(idx>=0) ans = max(ans,(suma[i]+sumb[idx])%m);
    }

    cout<<ans<<endl;

}