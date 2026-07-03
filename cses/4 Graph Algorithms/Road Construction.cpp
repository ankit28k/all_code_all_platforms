#include<bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> size,par;
    int maxsize , numofcomp;
public:
    dsu(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) par[i]=i;

        maxsize =1;
        numofcomp = n;
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
            maxsize = max(maxsize,size[upu]);
            par[upv] = upu;
        }

        else{
            size[upv] += size[upu];
            maxsize = max(maxsize,size[upv]);
            par[upu]=upv;
        }

        numofcomp--;
    }

    int getcomp(){
        return numofcomp;
    }

    int getmaxsz(){
        return maxsize;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    
    dsu ds(n);
    set<pair<int,pair<int,int>>> minh;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        
        if(ds.fup(a) != ds.fup(b)) ds.ubs(a,b);
        int numofcomp = ds.getcomp();
        int mxsz = ds.getmaxsz();

        cout<<numofcomp<<" "<<mxsz<<endl;

    }

    

}