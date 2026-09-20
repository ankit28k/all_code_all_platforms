#include<bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> par,size;
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
        int upu = fup(u) , upv = fup(v);
        if(upu==upv) return ;

        if(size[upu]>=size[upv]){
            size[upu]+=size[upv];
            par[upv] = upu;
        }
        else{
            size[upv]+=size[upu];
            par[upu] = upv;
        }
    }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        
        vector<pair<int,pair<int,int>>> arr(m);

        int sval = INT_MAX ;//sidx =-1,ss = -1,sx=-1,sy=-1;

        for(int i=0;i<m;i++) {
            int x,y,s;
            cin>>x>>y>>s;
            arr[i] ={s,{x,y}};
            
            if(abs(s-k) <sval){
                sval = abs(s-k);
                // sidx = i;
                // ss = s;
                // sx = x;
                // sy = y;
            }
        }

        dsu ds(n);
        vector<int> temp;

        //****
        //its like forcing sx and sy....say if there exists some one greater than k...it will be reduced to k...so why extra work
        //only needed if no one is bigger than k ...and we need to find the closest elemt to k

        // ds.ubs(sx,sy); 
        // temp.push_back(ss);
        



        //unnecessary complexity of set just sort the arr
        // set<pair<int,pair<int,pair<int,int>>>> pq;

        // for(int i=0;i<m;i++) {

        //     if(i==sidx) continue;
        //     int x=arr[i].second.first,y = arr[i].second.second,s =arr[i].first;
        //     pq.insert({s-k,{s,{x,y}}});
        // }

        // while(!pq.empty()){

        //     auto it = *(pq.begin());
        //     int d = it.first ,s = it.second.first, x = it.second.second.first,y = it.second.second.second;
        //     pq.erase(it);

        //     if(ds.fup(x) != ds.fup(y)){
        //         temp.push_back(s);
        //         ds.ubs(x,y);
        //     }
        // }



        sort(arr.begin(),arr.end());

        for(int i=0;i<m;i++){
            
            int s = arr[i].first ,x = arr[i].second.first, y = arr[i].second.second;
            // if(s==ss && sx==x && sy==y) continue;

            if(ds.fup(x) != ds.fup(y)){
                temp.push_back(s);
                ds.ubs(x,y);
            }
        }

        long long ans=0;
        int nt = temp.size(),cnt=0;
        for(int i=0;i<nt;i++){
            if(temp[i]>k) {
                ans += abs(k-temp[i]);
                cnt++;
            }
        }

        if(cnt==0) ans=sval;
    
        cout<<ans<<endl;

    }

}