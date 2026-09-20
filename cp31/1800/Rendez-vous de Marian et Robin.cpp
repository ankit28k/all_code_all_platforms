#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> djk(int src,vector<vector<pair<int,long long>>>& gr,vector<int>& ish,int n){

    vector<vector<long long>> dist(n+1,vector<long long>(2,1e18));
    dist[src][0]=0;
    if(ish[src]==1) dist[src][1] =0;
    
    set<pair<long long,pair<int,int>>> pq;
    pq.insert({0,{src,ish[src]}});

    while(!pq.empty()){
        auto top = *(pq.begin());
        pq.erase(top);

        long long d = top.first ;
        int x =top.second.first ,  hf = top.second.second;

        if(dist[x][hf] < d) continue;

        for(auto it : gr[x]){
            int cx = it.first ;
            long long ew = it.second;
            
            if(hf==1 || ish[x]==1) {
                long long newd = d+(ew/2);
                if(newd < dist[cx][1]) {
                    dist[cx][1] = newd;
                    pq.insert({newd,{cx,1}});
                }
            }

            else{
                long long newd = d+ew;
                if(newd < dist[cx][0]){
                    dist[cx][0] = newd;
                    pq.insert({newd,{cx,0}});
                }
                
            }
        }
    }

    return dist;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,h;
        cin>>n>>m>>h;
        vector<int> ish(n+1,0);
        for(int i=0;i<h;i++){
            int x;
            cin>>x;
            ish[x]=1;
        }

        vector<vector<pair<int,long long>>> gr(n+1);

        for(int i=0;i<m;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            gr[u].push_back({v,w});
            gr[v].push_back({u,w});
        }

        vector<vector<long long>> d1 = djk(1,gr,ish,n) , d2 = djk(n,gr,ish,n);

        long long ans=1e18;
        for(int i=1;i<=n;i++){
            ans = min(ans,max(d1[i][0],d2[i][0]));
            ans = min(ans,max(d1[i][1],d2[i][1]));
            ans = min(ans,max(d1[i][1],d2[i][0]));
            ans = min(ans,max(d1[i][0],d2[i][1]));
        }

        if(ans==1e18) cout<<-1<<endl;
        else cout<<ans<<endl;
        
    }

}