#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
 
    int minr = arr[0] + x , maxl = arr[0] - x , ans = 0 ;

    for(int i =1;i<n;i++){
      int templ = arr[i]-x , tempr = arr[i]+x ;
      minr = min(minr , tempr);
      maxl = max(maxl,templ);

      if (maxl > minr) {
        // No intersection → need to change affinity
        ans++;
        // Reset range to current pile
        minr = tempr;
        maxl = templ;
      }
    }
    
    cout<<ans<<endl;
    

    // vector<int> arr(n), maxp(n);

    // for (int i = 0; i < n; i++)
    // {
    //   cin >> arr[i];
    //   maxp[i] = arr[i] + x;
    // }

    // sort(maxp.begin(), maxp.end());
    // int ans = 0, k = 0;

    // for (int i = 0; i < n; i++)
    // {

    //   if (abs(arr[i] - maxp[k]) > x)
    //   {
    //     ans++;
    //     k = i;
    //   }
    // }

    // cout << ans << endl;
  }
}