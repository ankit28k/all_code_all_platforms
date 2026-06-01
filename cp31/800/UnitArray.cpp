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
    vector<int> arr(n);
    int ncount = 0, pcount = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      if (arr[i] == -1) ncount++;
      else pcount++;
    }

    int minoperation = 0;

     while (pcount < ncount)
    {
      pcount++;
      ncount--;
      minoperation++;
    }
    
    if(ncount % 2 != 0)
    {
      pcount++;
      ncount--;
      minoperation++;
    }

   

    cout << minoperation << endl;
  }
}