#include<bits/stdc++.h>
using namespace std;

void fun(int x,int par,vector<vector<int>>& gr,vector<vector<int>>& path){

    path[x].push_back(x);

    for(int cx:gr[x]){
        if(cx==par) continue;
        fun(cx,x,gr,path);

        for(int val:path[cx]){
            path[x].push_back(val);
        }
    }
    
}
int main(){
    int n;
    cin>>n;

    vector<int> par(n+1);
    for(int i=1;i<=n;i++) cin>>par[i];

    vector<vector<int>> gr(n+1);

    int root = -1;
    for(int i=1;i<=n;i++){
        if(par[i]== -1) root = i;
        else {
            int p = par[i];
            gr[p].push_back(i);
            gr[i].push_back(p);
        }
    }

    for(auto it:gr){
        sort(it.begin(),it.end());
    }
    vector<vector<int>> path(n+1);

    fun(root,-1,gr,path);

    int q;
    cin>>q;
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        int val,idx;
        cin>>val>>idx;

        idx--;
        if(path[val].size()<=idx) ans[i] = -1;
        else{
            ans[i] = path[val][idx];
        }
    }

    for(int x:ans) cout<<x<<" ";

}