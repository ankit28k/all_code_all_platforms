#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n), pre(m + 1);
        
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 1; i <= m; i++) cin >> pre[i];

        sort(arr.begin(), arr.end());

        int i = 1, j = n - 1;
        long long ans = 0;

        while (j >= 0)
        { 
            if (i <= m){

                if (pre[arr[j]] > pre[i]){
                    ans += pre[i];
                    j--;
                    i++;
                }

                else if (pre[arr[j]] <= pre[i]){
                    ans += pre[arr[j]];
                    j--;
                }
            }

            else{
                ans += pre[arr[j]];
                j--;
            }
        }

        cout << ans << endl;
    }
}