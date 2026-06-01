#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<vector<int>>& graph,vector<bool>& vis,vector<int>& ans){
    vis[src] = true;
    ans.push_back(src);

    for(int neigh: graph[src]){
        if(!vis[neigh]) dfs(neigh,graph,vis,ans);
    }
}

vector<int> fun(vector<vector<int>>& graph,vector<int>& arr,int n){

    vector<int> ans;
    vector<bool> vis(n+1,false);

    //the node from 0 to n-1 are connected ....only last one that is n is left

    // If n -> 0 exists, start at n...as 0 to n-1 is connected ...if n is connected to 0 => n->0->1->.....->n-1 
    if(arr[0]==1){
        graph[n].push_back(0);
        dfs(n,graph,vis,ans);
        return ans;
    }

    // If n-1 -> n exists start at 0 as 0 to n-1 is connected ...0->1->.....->n 
    else if(arr[n-1]==0){
        graph[n-1].push_back(n);
        dfs(0,graph,vis,ans);
        return ans;
    }
    
    else{
        //there is a road back from n -> i+1 (we can do the detour i -> n -> i+1) then i+1 to n-1 as all is connected
        for(int i=0;i<n-1;i++){ //n-2 as i+1 <=n-2 as n-1 is checked
            if(arr[i]==0 && arr[i+1]==1){

                //Remove the old edge (i -> i+1) so DFS is forced to go (i -> n)...otherwise it goes to i+1 as its above after pushing in list
                //ex = n = 3, arr: 0 1 1..... =>1 → 2 → 3.....   adj list-> 1: [2, 4].. 4:[2]....instead of 1->4->2 ...it goes 1->2->4
                graph[i].pop_back();
                graph[i].push_back(n);
                graph[n].push_back(i+1);

                dfs(0,graph,vis,ans);
                return ans;
            } 
        }
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

        vector<vector<int>> graph(n+1);
        for(int i=0;i<n-1;i++){
            graph[i].push_back(i+1);
        }

        vector<int> ans = fun(graph,arr,n);

        if(ans.size()==n+1){
            for(int i:ans) cout<<i+1<<" ";
            cout<<endl;
        }

        else cout<<-1<<endl;
    }

}