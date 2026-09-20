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
        long long maxi = *max_element(arr.begin(),arr.end()) + 1;

        long long ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,abs(arr[i]-maxi));
        }

        cout<<ans<<endl;
    }

}