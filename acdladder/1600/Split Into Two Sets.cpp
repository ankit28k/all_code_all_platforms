#include<bits/stdc++.h>
using namespace std;

class dsu{
public:
    vector<int> size,par;
    vector<int> vis;
    dsu(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        vis.resize(n+1,false);
        for(int i=0;i<=n;i++) par[i] =i;
    }

    int fup(int n){
        if(par[n]==n) return n;
        return par[n] = fup(par[n]);
    }
    void ubs(int u,int v){
        vis[u] = true ;
        vis[v] = true;
        int upu = fup(u) , upv = fup(v);
        if(upu==upv) return;


        if(size[upu]>=size[upv]){
            size[upu] += size[upv];
            par[upv] = upu;
        }

        else{
            size[upv] += size[upu];
            par[upu] = upv;
        }
    }
};

string fun(vector<pair<int,int>>& arr,int n){
    dsu ds1(n) ,ds2(n);
    for(int i=0;i<n;i++){
        int x = arr[i].first , y = arr[i].second;
        if(x==y) return "NO";
        bool is1 = ds1.vis[x] || ds1.vis[y];
        bool is2 = ds2.vis[x] || ds2.vis[y];

        if(is1 && is2) return "NO";
        else if(is1){
            ds2.ubs(x,y);
        }
        else {
            ds1.ubs(x,y);
        }
    }

    return "YES";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            arr[i] = {x,y};
        }
        cout<<fun(arr,n)<<endl;
    }

}