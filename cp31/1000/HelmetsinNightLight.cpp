#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,p;
    cin>>n>>p;
    vector<int> neigh(n) , cost(n);

    vector<pair<int,int>> costmax(n);

    for(int i=0;i<n;i++)cin>>neigh[i];
    for(int i=0;i<n;i++)cin>>cost[i];
    
    for(int i=0;i<n;i++){
      costmax[i] = {cost[i],neigh[i]};
    }

    sort(costmax.begin(),costmax.end());

    int vis =1;
    long long ans =p;

    for(int i=0;i<n;i++){
      if(vis>=n) break;

      if(costmax[i].first < p){
        int add = min(costmax[i].second , n - vis);  
        vis += add;

        ans+= 1LL*costmax[i].first * add;   
      }

      else break;
    }

    if(vis<n) ans+= 1LL*(n-vis)*p;
    cout<<ans<<endl;

    // // int vis =0 , i=0 ;
    // // long long ans =0;

    // int vis =1 , i=0 ;
    // long long ans =p;

    // while(i<n && costmax[i].first < p && vis<n){

    //   int add = min(costmax[i].second , n - vis); //total add including that arr[i]
    //   vis += add;

    //   ans+= costmax[i].first * (add);  //hence add-1 ..to not include that element
    //   i++;
    // }

    // ans += (n-vis)*p;
    // cout<<ans<<endl;


  }
}