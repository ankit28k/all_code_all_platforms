#include<bits/stdc++.h>
using namespace std;

long long fun(long long m,int a,int b,int n,vector<int>& arr){
    long long ans=0;
    for(int i=1;i<=m;i++){
        ans += 1LL*(a+b)*(arr[i]-arr[i-1]);
    }

    for(int i=m+1;i<=n;i++){
        ans += 1LL*b*(arr[i]-arr[m]);
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        vector<int> arr(n+1,0);
        for(int i=1;i<=n;i++) cin>>arr[i];

        long long ans=0;
        for(int i=1;i<=n;i++){
            ans += 1LL*(a+b)*(arr[i]-arr[i-1]);
        }

        int l=0,h=n;
        while(l<=h){
            int mid = l+(h-l)/2;
            long long temp = fun(mid,a,b,n,arr);

            // as the minimizing function is not...monotonic but u shaped convex function
            // if(temp<ans){
            //     ans = temp;
            //     h=mid-1;
            // }
            // else l = mid+1;

            ans = min(ans,temp);
            // CHANGED: Binary search condition for a convex (U-shaped) function
            if(mid < n && temp < fun(mid + 1, a, b, n, arr)){
                h = mid - 1; // Curve is rising, minimum is behind us (left)
            }
            else {
                l = mid + 1; // Curve is falling, minimum is ahead of us (right)
            }
        }

        cout<<ans<<endl;
    }

}