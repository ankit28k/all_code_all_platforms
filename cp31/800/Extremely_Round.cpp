#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int checkRound(int x)
{
  if (x <= 9)
    return x;
  else
  {
    string s = to_string(x);
    int n = s.size();
    int r = pow(10, n - 1);
    return ((n - 1) * 9) + (x / r);
  }
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int x;
    cin >> x;
    cout << checkRound(x) << endl;
  }
}