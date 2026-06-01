#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<long long, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        long long wt;
        cin >> x >> y >> wt;
        graph[x].push_back({wt, y});
    }

    vector<long long> dist(n + 1, -1e18);
    dist[1] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int x = 1; x <= n; x++)
        {

            if (dist[x] == -1e18)
                continue;
            for (auto it : graph[x])
            {
                int cx = it.second;
                long long edwt = it.first;

                if (dist[x] + edwt > dist[cx])
                {
                    dist[cx] = dist[x] + edwt;
                }
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int x = 1; x <= n; x++)
        {

            if (dist[x] == -1e18)
                continue;
            for (auto it : graph[x])
            {
                int cx = it.second;
                long long edwt = it.first;

                if (dist[x] == 1e18 || dist[x] + edwt > dist[cx])
                {
                    dist[cx] = 1e18;
                }
            }
        }
    }

    if (dist[n] == 1e18)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;
}