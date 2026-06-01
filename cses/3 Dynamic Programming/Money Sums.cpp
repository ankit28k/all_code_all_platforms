#include<bits/stdc++.h>
using namespace std;

int fun(int idx,int prev,vector<int>& arr,vector<int>& ans){
    if(idx<0) return;

    int t=0,nt=0;
    t = prev + arr[idx] + fun(idx-1,prev+arr[idx],arr,ans);
    ans.push_back(t);

    

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

}