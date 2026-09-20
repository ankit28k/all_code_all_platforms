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
    bool ubs(int u,int v){
        vis[u] = true ;
        vis[v] = true;
        int upu = fup(u) , upv = fup(v);
        if(upu==upv) return false;


        if(size[upu]>=size[upv]){
            size[upu] += size[upv];
            par[upv] = upu;
        }

        else{
            size[upv] += size[upu];
            par[upu] = upv;
        }
        return true;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int maxi=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        maxi = max(maxi,arr[i]);
    }

    vector<int> pos(maxi+1,-1);
    for(int i=0;i<n;i++){
        pos[arr[i]]=i;
    }

    dsu ds(n);
    long long ans=0;
    int edges=0;

    for(int g=maxi;g>=1;g--){

        int fidx = -1;
        
        for(int m=g;m<=maxi;m+=g){
            if(pos[m] != -1){
                if(fidx==-1){
                    fidx = pos[m];
                } 
                else {
                    if(ds.ubs(fidx, pos[m])){
                        ans += g;
                        edges++;
                        if(edges == n-1) break;
                    }
                }
            }
        }
        if(edges ==n-1) break;
    }

    cout<<ans<<endl;
}