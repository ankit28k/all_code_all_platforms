#include <bits/stdc++.h>
using namespace std;

int checkdivisible(int n)
{
  if (n == 1)
    return 0;

  int count = 0;
  while (n != 1)
  {

    if (n % 6 == 0)
    {
      n /= 6;
      count++;
    }

    else if (n % 3 == 0)
    {
      n *= 2;
      count++;
    }

    else
      return -1;
  }
  return count;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << checkdivisible(n) << endl;
  }
}