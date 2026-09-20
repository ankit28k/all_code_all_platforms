#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    long long k;
    cin>>n>>m>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    

    vector<bool> taken(n,false);

    int l=0,r=0;
    long long sum=0;
    vector<string> ans(n);
    while(r<m){
        sum+=arr[r];
        taken[r] = true;
        if(sum<=k) ans[r] = "Yes";
        else {
            ans[r] = "No";
            sum-=arr[r];
            taken[r] = false;
        }
        r++;
    }

    while(r<n){
        sum+=arr[r];
        taken[r] = true;
        if(taken[l]) sum-=arr[l];
        if(sum<=k) ans[r] = "Yes";
        else {
            ans[r] = "No";
            sum-=arr[r];
            taken[r] = false;
        }

        r++;
        l++;
    }

    for(auto x:ans) cout<<x<<endl;
}