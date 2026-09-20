#include<bits/stdc++.h>
using namespace std;

void dfs(int x,int par,vector<int>& time,int timer,vector<int>& low,vector<bool>& vis,vector<vector<int>>& gr,vector<pair<int,int>>& ans){
    vis[x] = true;
    time[x]= timer;
    low[x] = timer;

    timer++;

    for(int cx:gr[x]){
        if(cx==par) continue;
        if(!vis[cx]){
            dfs(cx,x,time,timer,low,vis,gr,ans);
            low[x] = min(low[x],low[cx]);

            if(low[cx]>time[x]) {
                ans.push_back({x,cx});
            }
        }

        else low[x] = min(low[x],time[cx]);
    }

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
    vector<pair<int,int>> ans;

    int timer =0;
    dfs(1,-1,time,timer,low,vis,gr,ans);
    cout<<ans.size()<<endl;
    for(auto it:ans){
        int a= it.first , b = it.second;
        cout<<min(a,b)<<" "<<max(a,b)<<endl;
    }
}