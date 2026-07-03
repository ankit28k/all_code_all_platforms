#include<bits/stdc++.h>
using namespace std;

void dfsb(int src,vector<bool>& vis,vector<vector<pair<int,int>>>& gr,int x,set<int>& sb){
    vis[src] = true;
    for(auto it:gr[src]){
        int nei = it.first , wt = it.second;
        if(!vis[nei]) {
            sb.insert(x^wt);
            dfsb(nei,vis,gr,x^wt,sb);
        }
    }
}

bool dfsa(int src,int b,vector<bool>& vis,vector<vector<pair<int,int>>>& gr,int x,set<int>& sb){

    vis[src] = true;
    // Validate the current node's state before evaluating edges. 
    // If checked inside the loop, the program will fail if the starting node itself 
    // is the winning state, or if the target 'b' is a direct neighbor and gets skipped.
    if(sb.find(x) != sb.end()) return true;

    for(auto it:gr[src]){
        int nei = it.first , wt = it.second;
        if(!vis[nei] && nei != b) {
            //if(sb.find(x^wt) != sb.end()) return true;
            if(dfsa(nei,b,vis,gr,x^wt,sb)) return true;
        }
    }

    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        vector<vector<pair<int,int>>> gr(n+1);
        for(int i=0;i<n-1;i++) {
            int x,y,wt;
            cin>>x>>y>>wt;
            gr[x].push_back({y,wt});
            gr[y].push_back({x,wt});
        }

        set<int> sb;
        vector<bool> vis(n+1,false);
        int x=0;
        dfsb(b,vis,gr,x,sb);

        vector<bool> vis2(n+1,false);
        if(dfsa(a,b,vis2,gr,x,sb)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

}