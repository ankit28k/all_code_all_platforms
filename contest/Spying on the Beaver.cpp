#include<bits/stdc++.h>
using namespace std;

// void dfs(int x,vector<vector<int>>& gr,vector<int>& par,vector<bool>& vis,vector<bool>& brr,vector<bool>& cam){

//     vis[x] = true;
//     int cnt=0;
//     for(int cx:gr[x]){
//         if(!vis[cx]){
//             dfs(cx,gr,par,vis,brr,cam);
//             if(brr[cx]) cnt++;
//         }
//     }
//     if(cnt==0){
//         if(brr[x]) cam[x] = true;
//     }
    
// }

bool dfs(int x, vector<vector<int>>& gr,vector<bool>& brr,vector<bool>& cam) {
    bool ht = brr[x];
    vector<int> tc;
    
    for(int cx : gr[x]) {
        if(dfs(cx, gr, brr, cam)) {
            tc.push_back(cx);
            ht = true;
        }
    }
    
    int c = tc.size();
    if(c > 0) {
        int req = brr[x] ? c : c - 1;
        for(int i = 0; i < req; i++) {
            cam[tc[i]] = true;
        }
    }
    
    return ht;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> gr(n+1);
        vector<int> par(n+1,-1);
        for(int i=2;i<=n;i++) {
            cin>>par[i];
            gr[par[i]].push_back(i);
        }

        int m;
        cin>>m;
        
        vector<bool> cam(n+1,false),brr(n+1,false);
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            brr[x] = true;
        }
        if(m==1) {
            cout<<0<<endl;
            continue;
        }

        dfs(1,gr,brr,cam);

        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cam[i]) cnt++;
        }
        cout<<cnt<<" ";
        for(int i=1;i<=n;i++){
            if(cam[i]) cout<<i<<" ";
        }
        cout<<endl;
    }

}