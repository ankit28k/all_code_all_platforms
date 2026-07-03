#include<bits/stdc++.h>
using namespace std;

bool poss(long long val,vector<long long>& arr,int n,int k){
    long long sum=0;
    int cnt=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum>val){
            sum=arr[i];
            cnt++;
        }
    }

    return cnt<=k;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    long long l=0, h=0 ;

    for(int i=0;i<n;i++){
        l=max(arr[i],l);
        h += arr[i];

    }

    long long ans =h;
    while(l<=h){
        long long m = l + (h-l)/2;
        if(poss(m,arr,n,k)){
            ans = m;
            h=m-1;
        }
        else l = m+1;
    }

    cout<<ans<<endl;
}