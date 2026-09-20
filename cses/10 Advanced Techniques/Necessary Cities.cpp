#include<bits/stdc++.h>
using namespace std;

void dfs(int x,int par,vector<int>& time,int timer,vector<int>& low,vector<bool>& vis,vector<vector<int>>& gr,vector<bool>& ap){
    vis[x] = true;
    time[x]= timer;
    low[x] = timer;

    timer++;
    int child =0;

    for(int cx:gr[x]){
        if(cx==par) continue;
        if(!vis[cx]){
            dfs(cx,x,time,timer,low,vis,gr,ap);
            low[x] = min(low[x],low[cx]);

            if(low[cx]>=time[x] && par != -1) {
                ap[x] = true;
            }
            child++;
        }

        else low[x] = min(low[x],time[cx]);
    }

    if(child>1 && par==-1) ap[x]=true;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n+1);
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<int> time(n+1) , low(n+1);
    vector<bool> vis(n+1,false);
    vector<bool> ap(n+1,false);

    int timer =0;
    dfs(1,-1,time,timer,low,vis,gr,ap);

    int cnt=0;
    for(int i=1;i<=n;i++) if(ap[i]) cnt++;

    cout<<cnt<<endl;
    for(int i=1;i<=n;i++) {
        if(ap[i]) cout<<i<<" ";
    }
    cout<<endl;
}