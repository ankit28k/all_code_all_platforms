#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n),brr(m);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++) cin>>brr[i];

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i-1]==brr[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }

    vector<int> ans;
    int i=n,j=m;
    while(i>0 && j>0){
        if(arr[i-1]==brr[j-1]){
            ans.push_back(arr[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }

    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<" ";
    cout<<endl;

}