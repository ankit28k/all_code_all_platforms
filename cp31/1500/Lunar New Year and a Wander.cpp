#include<bits/stdc++.h>
using namespace std;

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

    vector<bool> vis(n+1);
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minh;

    minh.push(1);

    vis[1] = true;

    while(!minh.empty()){
        int x = minh.top();
        minh.pop();

        ans.push_back(x);

        for(int cx:gr[x]){
            if(!vis[cx]) {
                vis[cx] = true;
                minh.push(cx);
            }
        }

    }

    for(int x:ans) cout<<x<<" ";
    cout<<endl;
}