#include<bits/stdc++.h>
using namespace std;

void dfs(int src,int par,vector<vector<int>>& graph,vector<int>& temp,vector<bool>& vis,bool& flag){

    vis[src] = true;
    temp.push_back(src);
    for(int cx:graph[src]){
        if(!vis[cx]) dfs(cx,src,graph,temp,vis,flag);
        else {
            if(cx != par) flag = true;
        }

    }

}
int main(){

    int n,m;
    cin>>n>>m;

    vector<int> ind(n+1,0);
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        ind[x]++;
        ind[y]++;
    }

    vector<bool> vis(n+1,false);
    map<int,vector<int>> mp;
    
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            bool flag = false;
            vector<int> temp;
            dfs(i,-1,graph,temp,vis,flag);
            if(flag) {
                mp[i] = temp;
            }
        }
    }

    int cnt=0;
    for(auto it:mp){
        vector<int>& temp = it.second;
        bool flag = true;
        for(int i=0;i<temp.size();i++){
            if(ind[temp[i]]>2) flag = false;
        }

        if(flag) cnt++;
    }
    cout<<cnt<<endl;
        
    

}