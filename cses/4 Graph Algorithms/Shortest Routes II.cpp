#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> dist(n+1,vector<long long>(n+1,1e18));
    for(int i=0;i<m;i++) {
        int x,y;
        long long wt;
        cin>>x>>y>>wt;
        dist[x][y]= min(wt,dist[x][y]);
        dist[y][x] = min(wt,dist[y][x]);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) dist[i][j]=0;
                if(dist[i][k] != 1e18 && dist[k][j] != 1e18) dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==1e18) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }

}