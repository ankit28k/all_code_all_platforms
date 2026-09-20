#include<bits/stdc++.h>
using namespace std;

long long fun(int mid,vector<int>& arr,vector<int>& brr,int n,int m){

    long long ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]<mid) ans+=mid-arr[i];
    }

    for(int i=0;i<m;i++){
        if(brr[i]>mid) ans+=brr[i]-mid;
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n),brr(m);

    int l=INT_MAX, h=INT_MIN;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        l=min(l,arr[i]);
        h=max(h,arr[i]);
    }
    for(int i=0;i<m;i++) {
        cin>>brr[i];
        l=min(l,brr[i]);
        h=max(h,brr[i]);
    }

    long long ans=LLONG_MAX;
    while(l<=h){
        int mid = l+(h-l)/2;
        long long temp = fun(mid,arr,brr,n,m);
        
        ans =min(ans,temp);
        if(temp<=fun(mid+1,arr,brr,n,m)) h=mid-1;
        else l= mid+1;
    }

    cout<<ans<<endl;


}