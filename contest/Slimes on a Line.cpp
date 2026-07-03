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
        int val = (arr[n-1] + arr[0])/2;

        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans,abs(arr[i]-val));
        }

        cout<<ans<<endl;
    }

}