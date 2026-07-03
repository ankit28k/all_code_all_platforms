#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int left,int m,int c0,int d0,vector<int>& arr,vector<int>& brr,vector<int>& crr,vector<int>& drr,vector<vector<int>>& dp){

    if(idx<0) {
        if(left>=c0) return (left/c0)*d0;
        else return 0;
    }
    
    if(dp[idx][left] != -1) return dp[idx][left];

    // int t =0,nt=0;
    // if(arr[idx]>=brr[idx] && left>= crr[idx]) {
    //     arr[idx] -= brr[idx];
    //     t = drr[idx] + fun(idx,left-crr[idx],m,c0,d0,arr,brr,crr,drr,dp);
    // }

    // nt = fun(idx-1,left,m,c0,d0,arr,brr,crr,drr,dp);.....
    
    //return dp[idx][left] = max(t,nt);

    // as arr[idx] -= brr[idx]; causes problem as its passed by reference......so thought of passing a vector copy to maintain frequency ...of 
    //how much of that bun made.....if(arr[idx] >= fq * brr[idx]) and no need of arr[idx]-=brr[idx]....but can give tle..hence used below one

    int ans=0;
    for(int fq=0; fq*brr[idx]<=arr[idx] && fq*crr[idx] <= left ;fq++){

        ans = max(ans,fq*drr[idx] + fun(idx-1,left- fq*crr[idx],m,c0,d0,arr,brr,crr,drr,dp));
    }

    return dp[idx][left] = ans;
    
}
int main(){
    int n,m,c0,d0;
    cin>>n>>m>>c0>>d0;
    vector<int> arr(m) , brr(m),crr(m),drr(m);
    for(int i=0;i<m;i++) {
        cin>>arr[i]>>brr[i]>>crr[i]>>drr[i];
    }

    vector<vector<int>> dp(m,vector<int>(n+1,-1));
    cout<<fun(m-1,n,m,c0,d0,arr,brr,crr,drr,dp)<<endl;

}