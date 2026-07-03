#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            arr[x - 1].push_back(i + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int sz = arr[i].size();
        cout << sz << " ";
        for (int j = 0; j < sz; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}