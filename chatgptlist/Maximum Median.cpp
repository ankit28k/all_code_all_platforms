#include<bits/stdc++.h>
using namespace std;

bool poss(long long m,int n,long long k,vector<int>& arr){

    int i= n/2;
    long long cnt=0;
    while(i<n){
        if(arr[i]<m) cnt += m-arr[i];
        else break;
        i++;
    }

    return cnt<=k;
}
int main(){
    int n;
    long long k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());

    long long l=0,h = k+arr[n-1];
    long long ans=-1;
    while(l<=h){
        long long m = l + (h-l)/2;
        if(poss(m,n,k,arr)){
            ans = m;
            l=m+1;
        }
        else h = m-1;
    }

    cout<<ans<<endl;

}