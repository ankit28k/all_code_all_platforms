#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){

    int a,b;
    cin>>a>>b;

    int ans =INT_MAX;
    
    for(int i=0;i<31;i++){ //as worst case when a = 10^9 or 2^30....and b=1...then it takes max 31 steps....b++ and a/b continously...

      int nb = b+i;
      if(nb==1) continue;

      int temp =a , cnt=i;

      while(temp>0){
        temp=temp/nb;
        cnt++;
      }

      ans = min(ans,cnt);
    }

    cout<<ans<<endl;


    // int count=0;
    
    // while(a>0) {
    //   if((b*b)>=(b+1)){
    //     a=a/b;
    //     a=a/b;
    //     count+=2;
    //   }
      
    //   else{
    //     b++;
    //     a=a/b;
    //     count+=2;
    //   }
    // }
    
    // cout<<count;
    // cout<<endl;

  }


}