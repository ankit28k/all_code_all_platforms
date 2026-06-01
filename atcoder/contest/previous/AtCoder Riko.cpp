#include<bits/stdc++.h>
using namespace std;

void fun(vector<int>& arr, long long sum,int n){

    vector<int> ans;
    map<int,int> mp(n,0);
    for(int i=0;i<n;i++) mp[arr[i]]++;
    
    int distinct =0;
    for(auto it = mp.begin();it!=mp.end();it++) {
        if(it->second ==0) distinct++;
    }

    if(arr[0] == arr[n-1]){
        cout<<arr[0]<<endl;
        return;
    }

    for(int i=(distinct/2);i<=n;i++){
        if(sum%i==0) ans.push_back(sum/i);
    }

    sort(ans.begin(),ans.end());
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
    return;

}
int main(){ 

    int n;
    cin>>n;
    vector<int> arr(n), ans;

    long long sum=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }

    sort(arr.begin(),arr.end());
    
    fun(arr,sum,n );
    

     
    

}