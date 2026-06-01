#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int arr[n];
  int minimum = INT_MAX;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n; i++)
  {
    minimum = min(minimum, abs(arr[i]));
  }

  cout << minimum;
}