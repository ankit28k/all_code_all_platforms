#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long long>>> gr(n+1);
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        gr[a].push_back({b,wt});
    }

    vector<vector<long long>> dist(n+1,vector<long long>(2,1e18));

    set<pair<long long,pair<int,int>>> pq;
    dist[1][0]=0;
    pq.insert({0,{1,0}});

    while(!pq.empty()){
        auto top = *(pq.begin());
        pq.erase(top);

        long long d = top.first ;
        int x= top.second.first , hf = top.second.second;

        if(dist[x][hf]<d) continue;
        
        for(auto it:gr[x]){
            long long ew = it.second;
            int cx = it.first;
            if(hf==0){
                long long nd1 = (ew/2) + d , nd2 = ew + d;
                if(dist[cx][1] > nd1){
                    dist[cx][1] = nd1;
                    pq.insert({nd1,{cx,1}});
                }
                if(dist[cx][0]>nd2){
                    dist[cx][0] = nd2;
                    pq.insert({nd2,{cx,0}});
                }
            }
            else{
                long long nd = ew + d;
                if(dist[cx][1] > nd){
                    dist[cx][1] = nd;
                    pq.insert({nd,{cx,1}});
                }
            }
        }
    }

    cout<<min(dist[n][0],dist[n][1])<<endl;

}