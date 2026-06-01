#include<bits/stdc++.h>
using namespace std;

 
long long fun(vector<vector<int>>& graph,int n){

    vector<int> vis(n+1,-1); 
    
    queue<int> q;
    q.push(1);
    vis[1] =0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neigh : graph[node]){
            if(vis[neigh] == -1 && vis[node]==0){
                vis[neigh] =1;
                q.push(neigh);
            }

            else if(vis[neigh] == -1 && vis[node]==1){
                vis[neigh] =0;
                q.push(neigh);
            }
        }
    }

    long long a =0, b =0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0) a++;
        else b++;
    }

    return a*b - (n-1); //total possible edges and net edges

}
int main(){ 

    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout<<fun(graph,n)<<endl;
    

}