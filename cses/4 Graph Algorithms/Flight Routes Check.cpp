#include<bits/stdc++.h>
using namespace std;

void dfs(int x,vector<vector<int>>& gr,vector<bool>& vis,stack<int>& st){
    vis[x] = true;
    for(int cx:gr[x]){
        if(!vis[cx]) dfs(cx,gr,vis,st);
    }

    st.push(x);
}

void dfs2(int x,vector<vector<int>>& grr,vector<bool>& vis){
    vis[x] = true;
    for(int cx:grr[x]){
        if(!vis[cx]) dfs2(cx,grr,vis);
    }
}

pair<int,int> fun(vector<vector<int>>& gr,vector<vector<int>>& grr,int n){

    vector<bool> vis1(n+1,false),vis2(n+1,false);
    stack<int> st;
    vector<int> temp1;
    for(int i=1;i<=n;i++){
        if(!vis1[i]) {
            dfs(i,gr,vis1,st);
            temp1.push_back(i);
        }
    }

    if(temp1.size()>1) return {temp1[0],temp1[1]};

    vector<int> temp2;
    while(!st.empty()){
        int i= st.top();
        st.pop();
        if(!vis2[i]) {
            dfs2(i,grr,vis2);
            temp2.push_back(i);
        }
    }

    int nt = temp2.size();
    if(nt>1) return {temp2[nt-1],temp2[nt-2]};
    else return {-1,-1};

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
    
    pair<int,int> ans = fun(gr,grr,n);
    if(ans.first==-1) cout<<"YES"<<endl;
    else {
        cout<<"NO"<<endl;
        cout<<ans.first<<" "<<ans.second<<endl;
    }
}