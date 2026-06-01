#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int prev,vector<int>& arr){
    
    if(idx<0) return 0;

    int take =0,nottake =0;
    if(arr[idx] ==arr[prev]) take = prev - idx +1;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
    }

}