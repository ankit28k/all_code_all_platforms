#include <bits/stdc++.h>
using namespace std;

int dfs(int src, vector<vector<int>> &gr, vector<int> &dp)
{

    int cnt = 0;
    for (int cx : gr[src]) {
        cnt += dfs(cx, gr, dp);
    }
    return dp[src] = cnt + 1;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> gr(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        gr[x].push_back(i);
    }

    vector<int> dp(n + 1, 0);
    dfs(1, gr, dp);
    for (int i = 1; i <= n; i++) cout << dp[i] -1<< " ";
    cout << endl;
}