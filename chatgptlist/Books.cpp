#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int l=0,r=0,ans=0;
    long long sum=0;
    while(r<n){
        sum += arr[r];
        while(l<=r && sum>t){
            sum -= arr[l];
            l++;
        }

        ans = max(r-l+1,ans);
        r++;
    }

    cout<<ans<<endl;
}