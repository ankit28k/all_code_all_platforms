#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());
    int i=0,j=n-1;

    long long ans=0 , sum=0;
    while(i<j){
        if(sum + arr[i] + arr[j]==x) {
            sum=0;
            ans++;
            i++;
            j--;
        }

        else if(sum + arr[i] + arr[j]>x){
            sum=arr[i];
            ans++;
            j--;
        }

        else if(arr[i] + arr[j]<x){
            sum+=arr[i];
            i++;
        }
    }

    cout<<ans<<endl;

}