#include<bits/stdc++.h>
using namespace std;

string fun(vector<int>& arr,int n){

    vector<long long> psum(n);
    psum[0] = arr[0]; 

    if(psum[0]>1) return "NO";

    for(int i=1;i<n;i++) psum[i] = psum[i-1] + arr[i];
    
    for(int i=0;i<n-1;i++){
        if(psum[i]<arr[i+1]) return "NO";
    }

    return "YES";

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr.begin(),arr.end());
        
        cout<<fun(arr,n)<<endl;
    }

}