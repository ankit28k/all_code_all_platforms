#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int t;
  cin >> t;
  vector<string> ans;
  while (t--)
  {
    long long n, k, x;
    cin >> n >> k >> x;
    long long minSum = (k * (k + 1)) / 2;         // 1+2+3.....k
    long long maxSum = k * n - (k * (k - 1)) / 2;  //(k * (2 * n + 1 - k)) / 2;   // n-k+1 + n-k+2.......n-1 + n

    if (x > maxSum || x< minSum)
      ans.push_back("NO"); 
    else
      ans.push_back("YES");
  }

  for (auto val : ans)
  {
    cout << val << endl;
  }
}