#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int l=0,r=0;
    long long sum=0,ans=0;
    while(r<n){
        sum+=arr[r];
        while(l<=r && (sum%n != 0)){
            sum-=arr[l];
            l++;
        }

        ans += r-l+1;
        r++;
    }
    cout<<ans<<endl;

}