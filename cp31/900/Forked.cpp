#include<bits/stdc++.h>
using namespace std;



int main(){
  int t;
  cin>>t;
  while(t--){
    int a,b,xk,yk,xq,yq;
    cin>> a>>b >>xk>>yk >> xq>>yq;
    
    set<pair<int,int>> movements = {
      {a,b} , {b,a} , 
      {-a,b} , {-b,a} , 
      {-a,-b} , {-b,-a} , 
      {a,-b} , {b,-a} 
    };

    set<pair<int,int>> s;
    for(auto movement : movements){ 
      s.insert({xk + movement.first ,yk + movement.second});
    }

    int count =0;
    for(auto movement : movements){ 
      if(s.find({xq + movement.first , yq + movement.second} ) != s.end()) count++;
      // if(s.count({xq + movement.first , yq + movement.second} )) count++;
    }

    cout<<count<<endl;
  }
}