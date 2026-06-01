#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int maxc = a[0];
    for (int i = 1; i < n; i++)
      maxc = max(maxc, a[i] - a[i - 1]);
    maxc = max(maxc, 2 * (x - a[n - 1]));
    cout << maxc << endl;
  }
}