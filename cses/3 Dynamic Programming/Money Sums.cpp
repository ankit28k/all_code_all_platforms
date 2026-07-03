#include<bits/stdc++.h>
using namespace std;

void fun(int idx,long long sum,vector<int>& arr,set<long long>& ans,vector<vector<bool>>& vis){
    if(idx<0) {
        if(sum>0) ans.insert(sum);
        return;
    }

    if(vis[idx][sum]) return;
    vis[idx][sum] = true;

    fun(idx-1,sum+arr[idx],arr,ans,vis);
    fun(idx-1,sum,arr,ans,vis);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    long long maxsum=0;

    for(int i=0;i<n;i++) {
        cin>>arr[i];
        maxsum += arr[i];
    }

    set<long long> ans;
    long long sum=0;
    vector<vector<bool>> vis(n,vector<bool>(maxsum+1,false));
    fun(n-1,sum,arr,ans,vis); 

    cout<<ans.size()<<endl;  
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;

}