#include<bits/stdc++.h>
using namespace std;

void dfs(int src,int prev,vector<vector<int>>& graph,vector<pair<int,int>>& ans,vector<int>& vis){

    if(prev != -1) ans.push_back({prev+1,src+1});
    vis[src] = true;

    for(auto neigh : graph[src]){
        if(!vis[neigh]) dfs(neigh,src,graph,ans,vis);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i] != arr[j]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<pair<int,int>> ans;
        vector<int> vis(n,false); 
        
        dfs(0,-1,graph,ans,vis);
        

        if(ans.size()<n-1) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(auto p : ans){
                cout<<p.first<<" "<<p.second<<endl;
            }
        }
        
    }

}