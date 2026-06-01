#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    long long sum=0;
    int l=0,r=0;

    pair<long long ,int> ans = {INT_MAX,-1};

    for(;r<k;r++){
        sum+=arr[r];
    } 

    if(ans.first>sum){
        ans.first = sum;
        ans.second = l;
    }

    while(r<n){
    
        sum-=arr[l];

        sum+=arr[r];

        l++;
        r++;
        if(ans.first>sum){
            ans.first = sum;
            ans.second = l;
        }

    }

    if(ans.first>sum){
        ans.first = sum;
        ans.second = l;
    }

    cout<<ans.second + 1<<endl;



}