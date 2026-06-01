#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n), ans;
    for (int i = 0; i < n; i++) cin >> arr[i];

    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
      if (arr[i] >= arr[i - 1])
        ans.push_back(arr[i]);
      else
      {
        ans.push_back(arr[i]);
        ans.push_back(arr[i]);
      }
    }

    int n2 = ans.size();
    cout << n2 << endl;
    for (int i = 0; i < n2; i++) cout << ans[i] << " ";
  }
}