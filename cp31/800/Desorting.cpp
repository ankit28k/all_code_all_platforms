#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
      return false;
  }

  return true;
}

int desort(vector<int> &arr, int n)
{
  int ans = INT_MAX;
  if (check(arr))
  {
    for (int i = 0; i < n - 1; i++)
    {
      ans = min(ans, abs(arr[i] - arr[i + 1]));
    }
    return ans / 2 + 1;
  }

  else
    return 0;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
      cin >> arr[i];

    cout << desort(arr, n) << endl;
  }
}