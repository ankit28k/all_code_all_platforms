#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<long long> nums(n);
  for(int i=0;i<n;i++) cin>>nums[i];

  long long sum=nums[0],maxsum = nums[0];

  for(int i=1;i<n;i++){

    sum = max(nums[i], sum + nums[i]); // sum+=nums[i] ...but left one is better
    maxsum=max(maxsum,sum);
 
    
  }

  cout<<maxsum<<endl;
}