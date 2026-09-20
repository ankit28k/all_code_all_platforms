#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

void dfs(int x,vector<vector<int>>& gr ,stack<int>& st,vector<bool>& vis){
    vis[x] = true;
    for(int cx:gr[x]){
        if(!vis[cx]) dfs(cx,gr,st,vis);
    }
    st.push(x);
}
void dfs2(int x,vector<vector<int>>& gr,vector<bool>& vis,int& t,vector<int>& arr,map<int,long long>& mp){
    vis[x] = true;
    for(int cx:gr[x]){
        if(!vis[cx]) dfs2(cx,gr,vis,t,arr,mp);
    }
    t = min(t,arr[x]);
    mp[arr[x]]++;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    vector<vector<int>> gr(n+1),grr(n+1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        grr[b].push_back(a);
    }

    vector<bool> vis1(n+1,false) , vis2(n+1,false);
    stack<int> st;

    for(int i=1;i<=n;i++){
        if(!vis1[i]) dfs(i,gr,st,vis1);
    }

    vector<int> temp ;
    long long ans=0 , ways =1;

    while(!st.empty()){
        int x = st.top();
        st.pop();
        
        if(!vis2[x]) {
            int t = INT_MAX;
            map<int,long long> mp;
            dfs2(x,grr,vis2,t,arr,mp);
            ans+=t;
            ways = (ways*mp[t])%mod;
        }
    }

    cout<<ans<<" "<<ways<<endl;
}