#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int a[3];
    for (int i = 0; i < 3; i++)
      cin >> a[i];
    if (a[0] + ((a[2] + 1) / 2) > a[1] + (a[2] / 2))
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
}