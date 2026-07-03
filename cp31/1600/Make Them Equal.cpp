#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int k,vector<int>& arr,vector<int>& brr,vector<int>& crr,vector<vector<int>>& dp,vector<int>& precomp){
    
    if(idx==arr.size()) return 0;

    if(dp[idx][k]!=-1) return dp[idx][k];

    int nt = fun(idx+1,k,arr,brr,crr,dp,precomp);
    int t=0;
    if(k>=precomp[brr[idx]]){
        t = crr[idx] + fun(idx+1,k-precomp[brr[idx]],arr,brr,crr,dp,precomp);
    }

    return dp[idx][k] = max(t,nt);

}
int main(){
    int t;
    cin>>t;

    vector<int> precomp(1001,-1);
    queue<int> q;
    q.push(1);
    precomp[1] = 0;

    while(!q.empty()){
        int val = q.front();
        q.pop();

        for(int x=1;x<=val;x++){

            int nval = val + (val/x);

            if(nval>1000) continue;  

            if(precomp[nval]==-1) {
                q.push(nval);
                precomp[nval] = precomp[val]+1;
            }
        }
    }

    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n,1) , brr(n) ,crr(n);
        for(int i=0;i<n;i++) cin>>brr[i];
        for(int i=0;i<n;i++) cin>>crr[i];

        /* OPTIMIZATION: Bounded Knapsack Capacity
            Why: K can be up to 10^6 and N up to 1000. A DP table of [1000][10^6] requires 4GB of RAM -> MLE.
            Logic: The max operations to reach 1000 from 1 is 12. For an array of size 1000, 
                we can NEVER spend more than 12 * 1000 = 12,000 operations total. 
                If K is larger than the sum of all required operations, the excess K is useless. 
                We cap K to shrink the DP table state space drastically.
        */
        int max_possible_k = 0;
        for(int i=0;i<n;i++) max_possible_k += precomp[brr[i]];
        k = min(k, max_possible_k);

        vector<vector<int>> dp (n,vector<int>(k+1,-1));
        cout<<fun(0,k,arr,brr,crr,dp,precomp)<<endl;
    }

}