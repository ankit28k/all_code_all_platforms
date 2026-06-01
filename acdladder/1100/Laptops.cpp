#include<bits/stdc++.h>
using namespace std;

string fun(vector<pair<int ,int>>& arr,int n){
    for(int i=0;i<n-1;i++){
        if((arr[i].first < arr[i+1].first) && (arr[i].second > arr[i+1].second)) return "Happy Alex";
    }

    return "Poor Alex";
}
int main(){

    int n;
    cin>>n;
    vector<pair<int ,int>> arr(n);
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        arr[i] = {a,b};
    }

    sort(arr.begin(),arr.end());
    cout<<fun(arr,n)<<endl;
}