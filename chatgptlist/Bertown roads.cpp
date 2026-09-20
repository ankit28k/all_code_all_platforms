#include<bits/stdc++.h>
using namespace std;

bool dfs(int x,int par,vector<int>& time,int& timer,vector<int>& low,vector<bool>& vis,vector<vector<int>>& gr){
    vis[x] = true;
    time[x]= timer;
    low[x] = timer;

    timer++;

    for(int cx:gr[x]){
        if(cx==par) continue;
        if(!vis[cx]){
            if(dfs(cx,x,time,timer,low,vis,gr)) return true;
            low[x] = min(low[x],low[cx]);

            if(low[cx]>time[x]) return true;
        }

        else low[x] = min(low[x],time[cx]);
    }
    return false;

}

void dfs2(int x,int par,vector<bool>& vis,vector<vector<int>>& gr,vector<pair<int,int>>& ans,vector<int>& time){

    vis[x] = true;
    for(int cx:gr[x]){
        if(cx==par) continue;
        if(!vis[cx]){
            ans.push_back({x,cx});
            dfs2(cx,x,vis,gr,ans,time);
        }
        /* 
        Why time[x] > time[cx] is required for back edges:
        Since the graph is undirected, every edge is seen from both ends. 
        Without this check, the descendant [a node visited later in the DFS path] 
        will add the back edge pointing UP, and when the recursion rolls back, 
        the ancestor [a node visited earlier in the DFS path] will see the same 
        edge and add it pointing DOWN.
        Checking time[x] > time[cx] ensures only the descendant processes this edge.
        */
        else if(time[x]>time[cx]) ans.push_back({x,cx});
        
    }

}

// if only needed to generate a graph..from undirected to directed
// void dfs(int x, int par, vector<int>& time, int& timer, vector<bool>& vis, vector<vector<int>>& gr, vector<pair<int,int>>& ans) {
//     vis[x] = true;
//     time[x] = timer;
//     timer++;

//     for (int cx : gr[x]) {
//         if (cx == par) continue;
        
//         if (!vis[cx]) {
//             // Tree Edge: Orient from Parent to Child
//             ans.push_back({x, cx});
//             dfs(cx, x, time, timer, vis, gr, ans);
//         } 
//         else if (time[x] > time[cx]) {
//             // Back Edge: Orient from Descendant to Ancestor
//             ans.push_back({x, cx});
//         }
//     }
// }
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
    int timer =0;

    bool flag = dfs(1,-1,time,timer,low,vis,gr);

    if(flag){
        cout<<0<<endl;
        return 0;
    }

    vector<pair<int,int>> ans;
    vector<bool> vis2(n+1,false);

    dfs2(1,-1,vis2,gr,ans,time);
    
    for(auto it:ans) cout<<it.first<<" "<<it.second<<endl;
}