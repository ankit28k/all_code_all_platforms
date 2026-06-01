#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    
    long long x, n;
    cin >> x >> n;

    long long ans;
    if (n % 4 == 0) ans = 0;
    else if (n % 4 == 1) ans = n;
    else if (n % 4 == 2) ans = -1;
    else ans = -n - 1;

    if (x % 2 == 0) x -= ans;
    else x += ans;

    cout << x << endl;
  }
  

}


  
// long long x, n;
//   cin >> x >> n;
//   long long d = 1;
//   while (n--) {
//     if (x%2 != 0)  x += d;
//     else  x -= d;
//     d++;
//   } 
//   cout<<x<<endl;


// Grasshopper Jump Pattern Simulation (x = 0)

// Step | x before | Even/Odd | Action | x after
// ----------------------------------------------
// 1    |     0    |  even    |  -1    |   -1
// 2    |    -1    |  odd     |  +2    |    1
// 3    |     1    |  odd     |  +3    |    4
// 4    |     4    |  even    |  -4    |    0
// 5    |     0    |  even    |  -5    |   -5
// 6    |    -5    |  odd     |  +6    |    1
// 7    |     1    |  odd     |  +7    |    8
// 8    |     8    |  even    |  -8    |    0
// 9    |     0    |  even    |  -9    |   -9
// 10   |    -9    |  odd     | +10    |    1

// Pattern Summary:

// n  | Final x
// ------------
// 1  | -1
// 2  |  1
// 3  |  4
// 4  |  0
// 5  | -5
// 6  |  1
// 7  |  8
// 8  |  0
// 9  | -9
// 10 |  1

// Pattern Rule (starting x = even):

// - If n % 4 == 0  → final x = 0
// - If n % 4 == 1  → final x = -n
// - If n % 4 == 2  → final x = 1
// - If n % 4 == 3  → final x = n + 1
