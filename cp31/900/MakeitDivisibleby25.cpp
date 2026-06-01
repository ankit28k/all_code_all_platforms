#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){

    string s ; 
    cin>>s; 
    int n=s.length();

    // int count =0, i = n-1;
    // while(i>1 ){
    //   if(s[i]=='0' && s[i-1]=='0') break;
    //   else if (s[i]=='0' && s[i-1]=='5') break;
    //   else if (s[i]=='5' && s[i-1]=='2') break;
    //   else if (s[i]=='5' && s[i-1]=='7') break;

    //   else {
    //     count++;
    //     i--;
    //   }
        
    // }

    // cout<<count<<endl;

    int ans = 1e9; // large number

    vector<string> targets = {"00", "25", "50", "75"};

    for (auto target : targets) {
      char second = target[1];
      char first = target[0];

      int pos2 = -1, pos1 = -1;

      // find second digit from right
      for (int i = n - 1; i >= 0; i--) {
          if (s[i] == second) {
            pos2 = i;
            break;
          }
      }

      if (pos2 == -1) continue; // not found second digit

      // find first digit left of second
      for (int i = pos2 - 1; i >= 0; i--) {
        if (s[i] == first) {
          pos1 = i;
          break;
        }
      }

      if (pos1 != -1) {
        // deletions needed = digits after second + digits between first and second
        int deletions = (n - pos2 - 1) + (pos2 - pos1 - 1);
        ans = min(ans, deletions);
      }
    }

    cout << ans << endl;

  }
}