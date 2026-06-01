#include<bits/stdc++.h>
using namespace std;

// long long fun(vector<int>& arr,long long c,int n){

//   //(ai + 2w)^2 = ai^2 + 4 w^2 + 4aiw = ai^2 sum + n*4w^2 + 4w * ai sum = c

//   long long sum =0, sqsum =0;
//   for(int i=0;i<n;i++){
//     sum+=arr[i];
//     sqsum += arr[i]*arr[i];
//   }

//   //b^2 - 4ac
//   long long d = (4*sum)*(4*sum) - 4*(n*4)*(sqsum - c);

//   //-b + sqrt(d) / 2a
//   long long w1 = (-4*sum + sqrt(d)) / 2*(n*4);
//   long long w2 = (-4*sum - sqrt(d)) / 2*(n*4);

//   if(w1>0) return w1;
//   else return w2;

// }

long long bs(vector<int>& arr,long long c,int n){
  
  long long l = 1,h = 1e9;
  while(l<=h){
    long long mid = l + (h-l)/2;

    long long temp = 0;
    bool overflow = false;

    for(int i=0;i<n;i++){
      long long side = arr[i] + 2*mid;

      // check before multiplication
      // If side > sqrt(c), then side*side > c, so multiplication would overflow
      if (side > 0 && side > sqrt(c)) {
        overflow = true;
        break;
      }

      temp += side*side;

      // Stop early if sum already exceeds c to avoid overflow and unnecessary work
      if (temp > c) {
        overflow = true;
        break;
      }
    }

    if(!overflow && temp < c) l = mid +1;
    else h = mid -1;

  }

  return l;

}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n ;
    long long c;
    cin>>n>>c;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<bs(arr,c,n)<<endl;
  }
}