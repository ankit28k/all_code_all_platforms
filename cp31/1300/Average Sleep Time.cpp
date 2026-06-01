#include<bits/stdc++.h>
using namespace std;
int main(){ 

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<long long> psum(n+1,0);
    psum[1] = arr[0];

    for(int i=2;i<=n;i++){
        psum[i] = psum[i-1] + arr[i-1];
    }


    long long sum=0;
    int l=1,r=k;    
    while(r<=n){
        sum+= psum[r]  - psum[l-1];
        l++;
        r++;
    }

    double ans = (double)sum/(n-k+1);
    cout<<fixed<<setprecision(10)<<ans<<endl;
    

}