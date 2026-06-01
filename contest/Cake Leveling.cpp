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

        long long sum=0,ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            sum += arr[i];
            long long t = sum/(i+1);
            ans = min(ans,t);
            cout<<ans<<" ";
        }
        cout<<endl;
    }

}