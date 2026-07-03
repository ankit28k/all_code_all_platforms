#include<bits/stdc++.h>
using namespace std;

class dsu{
public:
    vector<int> par,size;
    dsu(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) par[i] = i;
    }

    int fup(int n){
        if(par[n]==n) return n;
        return par[n] = fup(par[n]);
    }

    void ubs(int u,int v){
        int upu = fup(u) , upv = fup(v);
        if(upu==upv) return;
        
        if(size[upu]>=size[upv]){
            par[upv] = upu;
            size[upu] += size[upv];
        }
        else{
            par[upu] = upv;
            size[upv] += size[upu];
        }
    }
};

const long long mod = 1e9+7;
long long power(long long base, long long exp){
    long long ans=1;
    while(exp>0){
        if(exp%2==1) ans = (ans*base)%mod;
        base = (base*base)%mod;
        exp/=2;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;

    dsu ds(n);
    for(int i=0;i<n-1;i++) {
        int a,b,t;
        cin>>a>>b>>t;
        if(t==0) ds.ubs(a,b);
    }

    long long ans = power(n,k);

    for(int i=1;i<=n;i++){
        if(ds.fup(i)==i) {
            int sz = ds.size[i];
            ans = (ans - power(sz,k)+mod)%mod;
        }
    }

    cout<<ans<<endl;


}