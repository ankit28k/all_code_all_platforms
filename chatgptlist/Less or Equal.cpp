#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int k,int n){
    if(k==0) {
        if(arr[0]>1) return arr[0]-1;
        return -1;
    }
    if(k==n) return arr[n-1];
    if(arr[k-1] != arr[k]) return arr[k-1];
    return -1;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());
    cout<<fun(arr,k,n)<<endl;

}