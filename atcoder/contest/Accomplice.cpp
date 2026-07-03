#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        arr.push_back({x,0}); //0 -> arr
        arr.push_back({y,1}); //1 -> dep
    }

    sort(arr.begin(),arr.end());


}