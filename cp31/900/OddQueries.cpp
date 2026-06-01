#include <bits/stdc++.h>
using namespace std;


bool checkodd(int l,int r ,int k,vector<long long>& psum){

  long long tsum = psum.back();
  long long check_sum = tsum - (psum[r] - psum[l-1]) + k*(r-l+1); // as its 1 based indexing if it was 0 based.....r and l-1

  return (check_sum %2 == 1);

}

void checkq(vector<vector<long long>>& queries,vector<long long>& psum){
  
  for(auto it:queries){
    int l = it[0] , r = it[1];
    long long k = it[2];
    if(checkodd(l,r,k,psum)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,q;
    cin>>n>>q;
    vector<long long> arr(n);
    vector<vector<long long>> queries(q,vector<long long>(3));

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<q;i++){
      for(int j=0;j<3;j++){
        cin>>queries[i][j];
      }
    }
    
    vector<long long> psum(n+1,0);
    
    for(int i=1;i<=n;i++) {
      psum[i] = psum[i-1] + arr[i-1];
    }

    checkq(queries,psum);
  }
}