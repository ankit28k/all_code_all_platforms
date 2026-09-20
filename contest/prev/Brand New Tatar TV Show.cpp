#include<bits/stdc++.h>
using namespace std;

string fun(vector<int>& arr,int n,int k){
    
    if(arr[0] == arr[n-1]){
        if(n%2 != 0) return "NO";
        else return "YES";
    }
    
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr.begin(),arr.end());

    }

}