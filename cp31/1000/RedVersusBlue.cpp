#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,r,b;
    cin>>n>>r>>b;
 
    int k = r/(b+1); // divide r by b + 1, we get the minimum number of Rs that must go in every space.
    int left = r%(b+1); // division might not be perfect. The remainder tells us how many extra Rs we need to distribute.
    vector<char> ans(n);

    // Every space gets k Reds.
    // The first left spaces get 1 extra Red (so they have k+1).
    // We place a B after filling a space (except the very last space).
    
    int i=0;

    // We loop b+1 times because 'b' Blues create 'b+1' Red sections
    for(int step=0; step <= b; step++){

      for(int j=0;j<k;j++){
        ans[i] = 'R';
        i++;
      }

      if(left>0){
        left--;
        ans[i]='R';
        i++;
      }

      //Only add B if we are not at the very end...or only b times
      if(step<b){
        ans[i] = 'B';
        i++;
      }

    }

    for(auto x:ans) cout<<x;
    cout<<endl; 
  }

} 