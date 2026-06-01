#include <bits/stdc++.h>
using namespace std;

/*
This program balances the counts of "ab" and "ba" in a binary string.

Logic Summary:
---------------------------------------------
| Start | Transitions | End | ab | ba | Diff |
|--------|--------------|-----|----|----|------|
| a→b→a→b | a→b→a→b | b | 2 | 1 | +1 |
| b→a→b   | b→a→b   | b | 1 | 1 |  0 |
| a→b→a   | a→b→a   | a | 1 | 1 |  0 |
| b→a     | b→a     | a | 0 | 1 | -1 |

Observation:
- For any string of 'a' and 'b', |count("ab") - count("ba")| ≤ 1.
- If the counts differ, the string starts and ends with different letters.
- Flipping the first (or last) character makes the counts equal.
*/

int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    
    int ab =0 , ba =0;

    for(int i=0;i<s.length()-1;i++){
      if(s[i]=='a' && s[i+1] == 'b') ab++;
      if(s[i]=='b' && s[i+1] == 'a') ba++;
      
    } 

    if(ab != ba) {
      if(s[0]=='a') s[0] = 'b';
      else s[0] = 'a';
    }

    cout<<s<<endl; 

  }
}