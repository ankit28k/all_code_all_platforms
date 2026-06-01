#include<bits/stdc++.h>
using namespace std;

//we need max median so we take maximum numbers or numbers from last after sorting......that will fall at medain's index if spillited in k arrays
// ex 2 4 16 18 21 27 36 53 82 91 92 95 ....median after spilliting are at 1st index

// [2,91,92,95],[4,36,53,82],[16,18,21,27] The medians are 91,36,18 and Their sum is 145




int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n*k);
    for(int i = 0; i < n*k; i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    //int idx_max_el = ceil(n/2)-1; 
    int idx_max_el = ((n+1)/2) - 1;  //when split in k array ....the index where max element should be/ median of that array
    int idx_right = n-idx_max_el; //idx of that element from right or jump needed to take from right...ex ....3 for   [2,91,92,95],
    int jump = idx_right;

    int i= n*k- jump ;
    long long ans =0;
    while(k--){
      ans+= arr[i];
      i = i-jump;
    }

    cout<<ans<<endl;
  }

}