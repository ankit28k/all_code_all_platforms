#include<bits/stdc++.h>
using namespace std;

long long fun(vector<long long>& psum , int k , int n){

    long long maxi = LLONG_MIN , mini = LLONG_MAX;

    for(int i=k;i<=n;i+=k){
        maxi = max(maxi,abs(psum[i] - psum[i-k]));
        mini = min(mini,abs(psum[i] - psum[i-k]));
    }

    return maxi - mini;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        // if(n==1){    // gives runtime error
        //     cout<<0<<endl;
        //     continue;
        // }

        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        if(n==1){
            cout<<0<<endl;
            continue;
        }

        vector<long long> psum(n+1);

        psum[0] =0;
        psum[1] = arr[0];
        for(int i=2;i<=n;i++) psum[i] = psum[i-1] + arr[i-1];

        long long ans =0;
        for(int i=1;i<n;i++){
            if(n%i ==0){
                ans = max(ans,fun(psum,i,n));
            }
        }

        cout<<ans<<endl;

    }

}