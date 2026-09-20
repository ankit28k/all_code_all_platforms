#include<bits/stdc++.h>
using namespace std;

// void dfs(int x,int cpar,vector<bool>& vis,vector<vector<int>>& gr,vector<int>& par,vector<int>& ans){

//     if(ans.size()>0) return ;
//     vis[x] = true;
//     par[x] = cpar;

//     for(int cx:gr[x]){
//         if(!vis[cx]){
//             dfs(cx,x,vis,gr,par,ans);
//         }
//         else {
//             if(cx != cpar && vis[cx]) {
//                 vector<int> cycle;
//                 int curr = par[x];
//                 while(curr != -1) {
//                     cycle.push_back(x);
//                     curr = par[curr];
//                 }
//                 cycle.push_back(x);

//                 if(cycle.size()%2 != 0){
//                     ans = cycle;
//                     return;
//                 }
//             }
//         }
//     }

// }

void dfs(int x, int cpar, int d, vector<bool>& vis, vector<vector<int>>& gr, vector<int>& par, vector<int>& ans, vector<int>& depth) {
    if (ans.size() > 0) return;
    vis[x] = true;
    par[x] = cpar;
    depth[x] = d;

    for (int cx : gr[x]) {
        if (ans.size() > 0) return;
        if (!vis[cx]) {
            dfs(cx, x, d + 1, vis, gr, par, ans, depth);
        } 
        else {
            if (cx != cpar && vis[cx]) {
                if ((depth[x] - depth[cx]) % 2 == 0) {
                    vector<int> cycle;
                    int curr = x;
                    while (curr != cx) {
                        cycle.push_back(curr);
                        curr = par[curr];
                    }
                    cycle.push_back(cx);

                    ans = cycle;
                    return;
                }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        vector<vector<int>> gr(n+1);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }

        vector<bool> vis(n+1,false);
        vector<int> par(n+1,-1),ans,depth(n+1,0);
        
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,-1,0,vis,gr,par,ans,depth);
            }
        }
        if(ans.size()>0){
            cout<<ans.size()<<endl;
            for(int x:ans) cout<<x<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    

}