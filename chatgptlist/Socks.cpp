#include<bits/stdc++.h>
using namespace std;

class dsu{
public:
    vector<int> par,size;
    dsu(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++) par[i] = i;
    }

    int fup(int n){
        if(par[n] == n) return n;
        return par[n] = fup(par[n]);
    }

    void ubs(int u,int v){
        int upu= fup(u) ,upv = fup(v);
        if(upu == upv) return ;

        if(size[upu]>=size[upv]){
            size[upu] += size[upv];
            par[upv] = upu;
        }
        else{
            size[upv] += size[upu];
            par[upu]=upv;
        }
    }
};

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];

    dsu ds(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ds.ubs(a,b);
    }

    map<int,vector<int>> mp;
    for(int i=1;i<=n;i++){
        mp[ds.fup(i)].push_back(arr[i]);
    }

    long long ans = 0;
    for(auto& it:mp){
        vector<int>& temp = it.second;
        unordered_map<int,int> mp2;
        for(int x:temp) mp2[x]++;

        long long sum=0;
        int maxi=0;
        for(auto it2:mp2){
            maxi = max(maxi,it2.second);
            sum+=it2.second;
        }

        ans += sum-maxi;
    }

    cout<<ans<<endl;

}