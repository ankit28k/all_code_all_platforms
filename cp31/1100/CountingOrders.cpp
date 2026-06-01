#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n) , brr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];

        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());

        vector<int> greater_c(n);

        for(int i=0;i<n;i++){

            //instead of calculating manually used binary search ....to find no of elements greater than the number
            int idx = upper_bound(arr.begin(),arr.end(),brr[i]) - arr.begin(); 
            int count_greater = n - idx;
            
            greater_c[i] = count_greater;
        }

        long long ans =1;
        long long mod = 1e9+7;


        for(int i=n-1;i>=0;i--){
            long long choices = greater_c[i] - (n-1-i);
            if(choices<=0) {
                ans =0;
                break;
            }

            ans = (ans*choices) % mod;
        }

        cout<<ans<<endl;
    }

}