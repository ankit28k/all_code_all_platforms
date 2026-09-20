#include<bits/stdc++.h>
using namespace std;


// int fun(int idx,long long w,long long wt,long long ft,long long sum,int n,vector<long long>& arr,vector<vector<int>>& dp){

//     if(idx==n){
//         if(wt>=w && ft>= sum-w) return 1;
//         return 0;
//     }

//     if(dp[idx][w] != -1) return dp[idx][w];

//     int t = fun(idx+1,arr[idx]+w,wt,ft,sum,n,arr,dp);
//     int nt = fun(idx+1,w,wt,ft,sum,n,arr,dp);
//     return dp[idx][w] =t|nt;
// }
// bool poss(long long mid,long long w,long long f,long long sum,int n,vector<long long>& arr){

//     vector<vector<int>> dp(n,vector<int>(sum+1,-1));
//     return fun(0,0,w*mid,f*mid,sum,n,arr,dp);
// }


// storing all possible subset sum of w ..in possible_w_sum
void fun(int idx,int w,int n,vector<long long>& arr,vector<bool>& possible_w_sum,vector<vector<bool>>& dp){

    if(idx==n){
        possible_w_sum[w] = true;
        return;
    }

    if(dp[idx][w] != false) return;

    fun(idx+1,arr[idx]+w,n,arr,possible_w_sum,dp);
    fun(idx+1,w,n,arr,possible_w_sum,dp);
    dp[idx][w] = true;
    return;
}
bool poss(long long mid,long long w,long long f,long long sum,int n,vector<bool>& possible_w_sum){

    long long wt = mid*w , ft = f*mid;
    for(long long curr_w = 0;curr_w<=sum;curr_w++){
        if(possible_w_sum[curr_w]){
            if( wt>=curr_w && ft>=sum-curr_w) return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long w,f;
        cin>>w>>f;
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr.begin(),arr.end());
        long long sum=0;
        for(int x:arr) sum+=x;


        vector<bool> possible_w_sum(sum+1,false);
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));

        fun(0,0,n,arr,possible_w_sum,dp);

        long long l=0 , h = 1e6,ans=1e6;
        while(l<=h){
            long long mid = (l+h)/2;
            if(poss(mid,w,f,sum,n,possible_w_sum)){
                ans=mid;
                h=mid-1;
            }
            else l = mid+1;
        }

        cout<<ans<<endl;
    }

}