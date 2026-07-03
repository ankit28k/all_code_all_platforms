#include<bits/stdc++.h>
using namespace std;

class dsu{
public:
    vector<int> size,par;
    dsu(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++) par[i] =i;
    }

    int fup(int n){
        if(par[n]==n) return n;
        return par[n] = fup(par[n]);
    }
    void ubs(int u,int v){
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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        dsu ds(n);
        vector<int> ind(n+1,0);
        for(int i=1;i<=n;i++) {
            int x;
            cin>>x;
            if(ds.fup(i) != ds.fup(x)) ds.ubs(i,x);
            ind[x]++;
        }

        set<int> st;
        int cnt2 =0,total=0;
        for(int i=1;i<=n;i++){
            if(ds.fup(i)==i) {
                if(ds.size[ds.fup(i)] == 2) cnt2++;
                total++;
            }
            if(ind[i]==0) st.insert(ds.fup(i));

        }

        int min;
        if(st.size() + cnt2 > 1) min = total - st.size() - cnt2 + 1;
        else min = total;
        cout<<min<<" "<<total<<endl;

    }

}