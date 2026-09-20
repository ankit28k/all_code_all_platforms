#include<bits/stdc++.h>
using namespace std;

int dp[200][20][200];
int fun(int idx,int cnt,int left,vector<int>& arr){
    if(idx>=200) {
        if(cnt>1 && left==0) return 1;
        return 0;
    }

    if(dp[idx][cnt][left] != -1) return dp[idx][cnt][left];

    int t=0;
    if(left>=arr[idx]) t = fun(idx+1,cnt+1,left-arr[idx],arr);
    int nt = fun(idx+1,cnt,left,arr);

    return dp[idx][cnt][left] = nt+t;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(200);
    for(int i=0;i<200;i++){
        arr[i] = i+1;
    }

    memset(dp,-1,sizeof(dp));
    cout<<fun(0,0,n,arr);

}