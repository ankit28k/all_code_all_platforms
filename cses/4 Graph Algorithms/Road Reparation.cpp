#include<bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> size,par;
public:
    dsu(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) par[i]=i;
    }

    int fup(int n){
        if(par[n]==n) return n;
        return par[n] = fup(par[n]);
    }

    void ubs(int u,int v){
        int upu = fup(u) , upv  = fup(v);
        if(upu==upv) return;

        if(size[upu]>=size[upv]){
            size[upu]+= size[upv];
            par[upv] = upu;
        }

        else{
            size[upv] += size[upu];
            par[upu]=upv;
        }
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    
    dsu ds(n);
    set<pair<int,pair<int,int>>> minh;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        minh.insert({c,{a,b}});
    }

    long long ans=0;

    for(int i=0;i<m;i++){

        auto it = minh.begin();
        auto node = *it;
        int c = node.first , a = node.second.first ,b = node.second.second;
        minh.erase(it);

        int pa = ds.fup(a) , pb = ds.fup(b);
        if(pa != pb) {
            ds.ubs(a,b);
            ans += c;
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(ds.fup(i)==i) cnt++;
    }
    if(cnt==1) cout<<ans<<endl;
    else cout<<"IMPOSSIBLE"<<endl;


}