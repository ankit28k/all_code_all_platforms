#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int curr,int next,vector<int>& ans){

    if(curr == next ) return curr;

    if(ans[curr] != -1) return ans[curr];

    curr = next;
    next = arr[curr];
    return ans[curr] = fun(arr,curr,next,ans);
}

int main(){ 

    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];

    vector<int> ans(n+1,-1);
    for(int i=1;i<=n;i++){

        int curr = i;
        int next = arr[i]; 
        ans[i] = fun(arr,curr,next,ans);
    }

    for(int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}