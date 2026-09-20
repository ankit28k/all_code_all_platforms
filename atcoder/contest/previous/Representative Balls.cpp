#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ans(m + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int c, s;
        cin >> c >> s;
        ans[c] = max(ans[c], s);
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    cout << endl;
}