#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int l=0,r=0;
    long long sum=0 , ans=LLONG_MIN;
    while(r<n){

        sum += arr[r];
        while(l<=r && r-l+1 > b){
            sum-= arr[l];
            l++;
        }

        long long tsum =sum;
        int temp_l=l;
        while(temp_l<=r && r-temp_l+1 >=a){
            ans = max(ans,tsum);
            tsum-= arr[temp_l];
            temp_l++;
        }

        r++;
    }

    cout<<ans<<endl;

}