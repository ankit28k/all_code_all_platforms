#include<bits/stdc++.h>
using namespace std;

bool poss(int m,vector<int>& arr,int k,int n){

    int cnt=0,prev=0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[prev]>m){
            prev = i;
            cnt++;
        }
    }
    return cnt<=k;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int l=0,h=arr[n-1]-arr[0],ans=-1;
    while(l<=h){
        int m = l+(h-l)/2;
        if(poss(m,arr,k,n)){
            ans = m;
            h=m-1;
        }
        else l = m+1;
    }

    cout<<ans<<endl;
}