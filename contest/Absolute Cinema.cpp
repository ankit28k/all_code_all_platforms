#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n),brr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];

        long long sum=0;
        for(int i=0;i<n;i++){
            sum += max(arr[i],brr[i]);
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            long long csum = sum - max(arr[i],brr[i]) + arr[i] + brr[i];
            ans = max(csum,ans);
        }
        cout<<ans<<endl;

    }

}