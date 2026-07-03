#include<bits/stdc++.h>
using namespace std;

void dfs(int x,vector<vector<int>>& gr,vector<bool>& vis,stack<int>& st){
    vis[x] = true;
    for(int cx:gr[x]){
        if(!vis[cx]) dfs(cx,gr,vis,st);
    }

    st.push(x);
}

void dfs2(int x,vector<vector<int>>& grr,vector<bool>& vis,map<int,int>& mp,int cnt){
    vis[x] = true;
    mp[x] = cnt;

    for(int cx:grr[x]){
        if(!vis[cx]) dfs2(cx,grr,vis,mp,cnt);
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n+1) , grr(n+1);
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        grr[b].push_back(a);
    }
    

    vector<bool> vis1(n+1,false),vis2(n+1,false);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!vis1[i]) dfs(i,gr,vis1,st);
    }

    map<int,int> mp;
    int cnt=0;
    while(!st.empty()){
        int i= st.top();
        st.pop();
        if(!vis2[i]) {
            cnt++;
            dfs2(i,grr,vis2,mp,cnt);
        }
    }

    cout<<cnt<<endl;
    for(int i=1;i<=n;i++) cout<<mp[i]<<" ";
    cout<<endl;
}