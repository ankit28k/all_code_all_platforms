#include <bits/stdc++.h>
using namespace std;

int dfs(int src, vector<vector<int>> &gr, vector<bool> &vis, int &ans)
{
    vis[src] = true;
    int l_m1 = 0,r_m2=0;
    for (int cx : gr[src])
    {
        if (!vis[cx]){
            int curr = dfs(cx, gr, vis, ans);
            if(curr>l_m1) {
                r_m2 = l_m1;
                l_m1 = curr;
            }

            else if(curr>r_m2) r_m2 = curr;
        }
    }

    ans = max(ans, l_m1 + r_m2); //l_m1 + r_m2+1 as it gives nodes ....but we need edges as diameter
    return l_m1 + 1 ;//max(l,r) + 1;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> gr(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    int ans = 0;
    vector<bool> vis(n + 1);
    dfs(1,gr,vis,ans);
    cout << ans<< endl;
}