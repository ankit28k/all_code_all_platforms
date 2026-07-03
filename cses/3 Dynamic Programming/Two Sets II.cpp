#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;


long long fun(int idx,long long left,vector<int>& arr,vector<vector<long long>>& dp){
    if(left==0) return 1;
    if(idx<0 ) return 0;

    if(dp[idx][left] != -1) return dp[idx][left];
    long long t=0,nt=0;
    if(left>=arr[idx]) t = fun(idx-1,left-arr[idx],arr,dp);
    nt = fun(idx-1,left,arr,dp);

    return dp[idx][left] = (t+nt)%mod;

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    long long sum=0;
    for(int i=0;i<n;i++) {
        arr[i] = i+1;
        sum+=arr[i];
    }
    
    long long ans;
    if(sum%2 == 0) {
        long long val = sum/2;
        vector<vector<long long>> dp(n,vector<long long>(val+1,-1));
        ans = fun(n-2,val,arr,dp);
        
        
        //ans = (fun(n-1,val,arr,dp)/2)%mod;
        /* Why n-2? 
        If we use n-1, the DP counts both subsets A and B, counting every valid partition twice.
        Dividing the final answer by 2 breaks because of modulo arithmetic and integer overflow.
        By stopping at n-2, we ban the n-th element from our DP choices, anchoring it 
        permanently to the other subset. This shatters the mirror effect, ensuring each 
        unique partition is counted exactly once. 
        */
    }
    else ans=0;
    cout<<ans<<endl;
    
    

}