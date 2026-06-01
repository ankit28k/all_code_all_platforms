#include <bits/stdc++.h>
using namespace std;

int hcf(int a, int b)
{
  if (b == 0)
    return a;
  return hcf(b, a % b);
}
int lcm(int a, int b)
{
  return (a / hcf(a, b)) * b; // return (a*b)/hcf(a,b);   safer to avoid overflow
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;


    int bestA = 1, bestB = n - 1;
    int minLCM = lcm(bestA, bestB); 

    // Iterate up to sqrt(n) and use divisor symmetry
    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        int d1 = i;
        int d2 = n / i;

        // try a = d1, b = n - d1
        if (d1 < n) {
          long long curLCM = lcm(d1, n - d1);
          if (curLCM < minLCM) {
            minLCM = curLCM;
            bestA = d1;
            bestB = n - d1;
          }
        }

        // try a = d2, b = n - d2
        if (d2 < n && d1 != d2) {
          long long curLCM = lcm(d2, n - d2);
          if (curLCM < minLCM) {
            minLCM = curLCM;
            bestA = d2;
            bestB = n - d2;
          }
        }
      }
    }

    cout << bestA << " " << bestB << "\n";
    
    // int ans = INT_MAX;
    // int bestA = 1, bestB = n - 1;

    // for (int i = max(1, n / 2 - 100); i <= min(n - 1, n / 2 + 100); i++) //int i = 1; i <= n / 2; i++
    // {
    //   int a = i, b = n - i;
    //   int currentLCM = lcm(a, b);
    //   if (currentLCM < ans)
    //   {
    //     ans = currentLCM;
    //     bestA = a;
    //     bestB = b;
    //   }
    // }

    // cout << bestA << ' ' << bestB << '\n'; // Add newline here!
 
  }
}
