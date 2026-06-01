#include<bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> size,par;
public:
    dsu(int n){
        size.resize(n+1,0);
        par.resize(n+1);

        for(int i=0;i<n+1;i++) par[i] =i;
    }

    int findupar(int u){
        if(par[u]==u) return u;
        return par[u] = findupar(par[u]);
    }

    void ubs(int u,int v){
        int upu = findupar(u) , upv = findupar(v);

        if(upu == upv) return;

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
    
    int n,m1,m2;
    cin>>n>>m1>>m2;
    
    if(m1==n-1 || m2==n-1){
        cout<<0<<endl;
        return 0;
    }

    dsu ds1(n),ds2(n);
    for(int i=0;i<m1;i++){

        int x,y;
        cin>>x>>y;
        ds1.ubs(x,y);
    }

    for(int i=0;i<m2;i++){

        int x,y;
        cin>>x>>y;
        ds2.ubs(x,y);
    }
    
    vector<pair<int,int>> ans;
    map<int,bool> mp1,mp2;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){

            int upi1 = ds1.findupar(i),upi2 = ds1.findupar(j) ;
            int upj1 = ds2.findupar(i) , upj2 = ds2.findupar(j);

            if(mp1[upi1] == false && mp1[upi2]==false && mp2[upj1] == false && mp2[upj2]==false){

                if( upi1 != upi2  &&  upj1 != upj2){
                    ans.push_back({i,j});

                    ds1.ubs(upi1,upi2);
                    ds2.ubs(upj1,upj2);
                    // mp1[upi1] = true;
                    // // mp1[upi2] = true;
                    // mp2[upj1] = true;
                    // // mp2[upj2] = true;
                }
            }
            
        }
    }

    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;

}