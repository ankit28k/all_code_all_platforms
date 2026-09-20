#include<bits/stdc++.h>
using namespace std;

void dfs(int x,vector<vector<int>>& gr,vector<int>& crr,vector<bool>& dt,vector<bool>& vis){

    vis[x] = true;
    bool fl = true;

    for(int cx:gr[x]){
        if(!vis[cx]){
            dfs(cx,gr,crr,dt,vis);
            if(crr[cx]==0) fl = false;
        }
    }

    if(fl && crr[x]==1) dt[x]=true;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> gr(n+1);
    vector<int> crr(n+1);

    int root = -1;
    for(int i=1;i<=n;i++) {
        int p,c;
        cin>>p>>c;
        if(p!=-1) gr[p].push_back(i);
        else root=i;
        crr[i]=c;

    }

    vector<bool> dt(n+1,false) , vis(n+1,false);
    dfs(root,gr,crr,dt,vis);

    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(dt[i]) {
            cout<<i<<" ";
            cnt++;
        }
    }
    if(cnt==0) cout<<-1<<endl;
    else cout<<endl;

}