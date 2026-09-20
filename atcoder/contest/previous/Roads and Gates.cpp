#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,y;
    cin>>n>>m>>y;
    vector<vector<pair<long long,long long>>> gr(n+2);
    for(int i=0;i<m;i++) {
        long long a,b, wt;
        cin>>a>>b>>wt;
        gr[a].push_back({b,wt});
        gr[b].push_back({a,wt});
    }

    vector<long long> wrapv(n+1);
    for(int i=1;i<=n;i++) {
        cin>>wrapv[i];
        gr[i].push_back({n+1,wrapv[i]+y});
        gr[n+1].push_back({i,wrapv[i]});
    }

    vector<long long> dist(n+2,1e18);
    set<pair<long long,long long>> pq;
    pq.insert({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        auto top = *(pq.begin());
        long long d = top.first , x = top.second;
        pq.erase(top);

        if(d>dist[x]) continue;

        for(auto it:gr[x]){
            long long cx = it.first , wt = it.second;
            if(dist[cx] > dist[x] + wt ){
                dist[cx] = dist[x] + wt;
                pq.insert({dist[cx],cx});
            }
        }
    }

    for(int i=2;i<=n;i++) cout<<dist[i]<<" ";
    cout<<endl;

}