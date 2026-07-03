#include<bits/stdc++.h>
using namespace std;

bool bfs(int src,vector<int>& vis,vector<vector<pair<int,string>>>& gr,int& c0,int& c1){
    queue<int> q;
    q.push(src);
    vis[src]=0;
    c0++;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto it:gr[x]){
            string s = it.second;
            int cx = it.first;

            int color;
            if(s=="imposter") color = 1-vis[x];
            else if(s=="crewmate") color = vis[x];


            if(vis[cx]==-1){

                vis[cx]=color;
                q.push(cx);
                if(color==0) c0++;
                else c1++;
            }
            else if(vis[cx] != -1 && vis[cx] != color) return false;
        }

    }

    return true;
}

int fun(int n,int m,vector<int>& vis,vector<vector<pair<int,string>>>& gr){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==-1) {
            int c0=0,c1=0;
            if(bfs(i,vis,gr,c0,c1) == false) return -1;
            cnt += max(c0,c1);
        }
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,string>>> gr(n+1);
        vector<int> vis(n+1,-1);
        for(int i=0;i<m;i++) {
            int a,b;
            string s;
            cin>>a>>b>>s;
            gr[a].push_back({b,s});
            gr[b].push_back({a,s});
        }

        cout<<fun(n,m,vis,gr)<<endl;

    }

}