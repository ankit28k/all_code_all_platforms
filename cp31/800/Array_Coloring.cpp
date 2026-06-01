#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  vector<string> results;

  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    int ocount = 0, ecount = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[i] % 2 == 0)
        ecount++;
      else
        ocount++;
    }

    if (ocount % 2 == 0 && ecount % 2 == 0)
      results.push_back("Yes");
    else if (ocount % 2 == 0 && ecount % 2 != 0)
      results.push_back("Yes");

    else
      results.push_back("No");
  }

  for (const string &res : results)
    cout << res << endl;

  return 0;
}

 