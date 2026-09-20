#include <bits/stdc++.h>
using namespace std;

long long minToll(int n, vector<array<int, 3>> &roads, vector<int> &fees,
                  int maxTime, int src, int dest) {
    

    vector<vector<pair<int ,long long>>> gr(n);
    for(auto it:roads){
        int a = it[0] , b = it[1] , w = it[2];
        gr[a].push_back({b,w});
        gr[b].push_back({a,w});
    }

    vector<vector<long long>> dist(n,vector<long long>(maxTime+1,1e18));
    dist[src][0] = fees[src];

    set<pair<long long,pair<int,long long>>> pq;
    pq.insert({fees[src],{src,0}});

    while(!pq.empty()){
        auto top = *(pq.begin());
        pq.erase(top);
        long long feex = top.first  ;
        int x = top.second.first , time = top.second.second;

        if(feex> dist[x][time]) continue;

        for(auto it:gr[x]){
            int cx = it.first ;
            long long ew = it.second  , feecx = fees[cx];

            if(ew + time <= maxTime ){
                if(feecx + feex < dist[cx][time + ew]){
                    dist[cx][time + ew] = feecx + feex;
                    pq.insert({dist[cx][time+ew],{cx,time +ew}});
                }
                
            }
        }
    }
    long long ans=1e18;
    for(long long i=0;i<=maxTime;i++){
        ans = min(ans,dist[dest][i]);
        
    }

    if(ans != 1e18) return ans;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, maxTime;
    cin >> n >> m >> maxTime;
    vector<int> fees(n);
    for (int i = 0; i < n; i++) cin >> fees[i];
    vector<array<int, 3>> roads(m);
    for (int i = 0; i < m; i++) cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    int src, dest;
    cin >> src >> dest;
    cout << minToll(n, roads, fees, maxTime, src, dest) << "\n";
    return 0;
}
