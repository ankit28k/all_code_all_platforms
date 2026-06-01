#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<long long> ans(n); 

        for(int i=0;i<n-2;i++){
            long long k = (arr[i+2] - 2*arr[i+1] + arr[i])/2;
            ans[i+1] = k; 
        }

        long long s0=0,sn=0;
        for(int i=1;i<n-1;i++){
            s0 += ans[i]*i;
            sn += ans[i]*(n-1-i);
        } 
        ans[0] = (arr[n-1] - sn)/(n-1);
        ans[n-1] = (arr[0] - s0)/(n-1);

        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

}