#include <bits/stdc++.h>
using namespace std;

static const long long mod = 1000000007LL;

long long fun(int idx,int n,const vector<int>& arr,vector<long long>& dp){

    if(idx>n) return 0;
    if(idx==n) return 1;

    if(dp[idx] != -1 ) return dp[idx];
    long long ans=0;
    for(int i=1;i<=arr[idx];i++){
        ans = (ans + fun(idx+i,n,arr,dp))%mod;
    }
    return dp[idx] = ans;
}
vector<long long> countWays(int nodeCount, const vector<int>& maxJump, const vector<int> &queries) {
    
    int qn = queries.size();
    vector<long long> ans(qn);

    for(int i=0;i<qn;i++){
        int n = nodeCount;
        vector<long long> dp(n+1,-1);
        int s = queries[i];
        ans[i] = fun(s,n,maxJump,dp);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodeCount;
    if (!(cin >> nodeCount)) {
        return 0;
    }

    vector<int> maxJump(nodeCount + 1, 0);
    for (int node = 1; node <= nodeCount; ++node) {
        cin >> maxJump[node];
    }

    int queryCount;
    cin >> queryCount;

    vector<int> queries(queryCount);
    for (int i = 0; i < queryCount; ++i) {
        cin >> queries[i];
    }

    vector<long long> answers = countWays(nodeCount, maxJump, queries);
    for (size_t i = 0; i < answers.size(); ++i) {
        cout << answers[i] << '\n';
    }
    return 0;
}
