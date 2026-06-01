#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());

        int ans=n;
        for(int i=0;i<n;i++){
            int lel = lower_bound(arr.begin(),arr.end(),arr[i]) - arr.begin();
            int gidx = upper_bound(arr.begin(),arr.end(),arr[i]) - arr.begin();
            int gel = n-gidx;

            ans = min(ans,max(lel,gel));
        }

        cout<<ans<<endl;
    }

}