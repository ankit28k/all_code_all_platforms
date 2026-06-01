#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long x, y, k;
    cin >> x >> y >> k;

    // total stick required = k + yk ....stick + coals
    //  1 + (x-1)n  ....n operation to make t sticks
    //  n = (k + yk -1 )/x-1 ....stick_trade
    //  k = charcol_trade

     
    long long ans = (k + y*k -1 + x-2)/(x-1) + k;

    cout << ans << endl;
  }
}