#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> gr(n);
    for(int i=0;i<n;i++) {
        int a,b,w;
        cin>>a>>b>>w;
        gr[a].push_back({w,b});
        gr[b].push_back({w,a});
    }

    vector<pair<int,pair<int,int>>> dist(n , {1e9,{INT_MAX,INT_MIN}});
    set<pair<int,pair<int,int>>> pq;


}