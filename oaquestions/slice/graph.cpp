#include<bits/stdc++.h>
using namespace std;

void dfs(int x,int par,vector<vector<int>>& gr,vector<int>& ht,vector<int>& nodes){

    int ch=0 , nd=1;
    for(int cx:gr[x]){
        if(cx == par) continue;
        dfs(cx,x,gr,ht,nodes);
        ch = max(ch,ht[cx]);
        nd += nodes[cx];
    }
    ht[x] = ch+1;
    nodes[x] = nd;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> gr(26);
    for(int i=0;i<n;i++) {
        char a,c,b;
        cin>>a>>c>>b;
        gr[a-'A'].push_back(b-'A');
        gr[b-'A'].push_back(a-'A');
    }

    vector<int> ht(26) , nodes(26);
    dfs(0,-1,gr,ht,nodes);

    vector<vector<vector<int>>> grr(26);
    for(int x=0;x<26;x++) {
        for(int cx:gr[x]){
            grr[x].push_back({ht[cx],nodes[cx],cx});
        }
    }

    for(auto& v:grr){
        sort(v.rbegin(),v.rend());
    }

    vector<bool> vis(26,false);
    vector<int> lev(26,0);
    vis[0] = true;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        int cnt=1;
        for(auto it:grr[x]){
            int cx = it[2];
            if(!vis[cx]){
                q.push(cx);
                vis[cx]=true;
                lev[cx] = lev[x]+cnt;
                cnt++;

            }
        }
    }

    int ans=0;
    for(int x:lev) ans = max(ans,x);
    cout<<ans<<endl;

}