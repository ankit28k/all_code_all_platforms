#include <bits/stdc++.h>
using namespace std;

int fun(vector<long long>& arr,long long x,long long n){

    int r=0,l=0;
    long long sum=0 , ans=0;
    while(r<n){
        sum+=arr[r];
        while(l<=r && sum>x){
            sum -= arr[l];
            l++;
        }

        ans+=r-l+1;
        r++;

    }

    return ans;
}
int main(){
    
    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cout<<fun(arr,x,n) - fun(arr,x-1,n)<<endl;
}
