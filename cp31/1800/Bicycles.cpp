#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        vector<vector<pair<int,long long>>> gr(n+1);
        for(int i=0;i<m;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            gr[u].push_back({v,w});
            gr[v].push_back({u,w});
        }

        vector<int> s(n+1);
        int maxi = 1;
        for(int i=1;i<=n;i++){
            cin>>s[i];
            maxi=max(maxi,s[i]);
        }


        vector<vector<long long>> dist(n+1,vector<long long>(maxi+1,1e18));
        dist[1][s[1]]=0;
        
        set<pair<long long,pair<int,int>>> pq;
        pq.insert({0,{1,s[1]}});

        while(!pq.empty()){
            auto top = *(pq.begin());
            pq.erase(top);

            long long d = top.first ;
            int x =top.second.first ,  sx = top.second.second;

            if(dist[x][sx] < d) continue;

            for(auto it : gr[x]){
                int cx = it.first ;
                long long ew = it.second;

                int currs = min(sx,s[x]);

                long long newd = d + ew*currs;
                if(newd < dist[cx][currs]){
                    dist[cx][currs] = newd;
                    pq.insert({newd,{cx,currs}});
                }
            }
        }

        long long ans=1e18;
        for(int i=1;i<=maxi;i++){
            ans = min(ans,dist[n][i]);
        }

        if(ans==1e18) cout<<-1<<endl;
        else cout<<ans<<endl;
        
    }

}