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

        sort(arr.begin(),arr.end());

        vector<long long> psum(n);
        psum[0] = brr[0];
        for(int i=1;i<n;i++) psum[i] = psum[i-1]+brr[i];

        long long ans= 0;

        for(int i=0;i<n;i++){
            
            int difficulty = arr[i];
            //int greater_el = upper_bound(arr.begin(),arr.end(),i+1) - arr.begin() ; //numbers greater than that level or swords_available
            int swords_available= n-i;

            // //levels crossable.......upper_bound finds the first prefix sum > swords_available
            int levels = upper_bound(psum.begin(),psum.end(),swords_available) - psum.begin(); 

            long long score = 1LL*difficulty*levels;//difficulty * levels crossed

            ans = max(ans,score);
        }

        cout<<ans<<endl;
    }

}