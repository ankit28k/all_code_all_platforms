#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    long long x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<long long> arr(n);
    arr[0]=x;
    for(int i=1;i<n;i++) arr[i] = (a*arr[i-1]+b)%c;

    long long sum=0 , ans =0;
    int r=0,l=0;
    for(;r<k;r++) sum+=arr[r];
    ans ^= sum;

    while(r<n){
        
        sum+=arr[r];

        sum -= arr[l];
        r++;
        l++;
        ans ^= sum;
    }
    cout<<ans<<endl;
}