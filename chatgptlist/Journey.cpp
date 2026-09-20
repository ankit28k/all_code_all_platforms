#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> gr(n+1);
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<bool> vis(n+1,false);
    vector<double> pe(n+1);
    vector<int> lev(n+1,0);
    queue<int> q;
    q.push(1);

    vis[1] = true;
    pe[1]=1;

    double ans=0;
    while(!q.empty()){

        int x = q.front();
        q.pop();

        int cnt=0;
        for(int cx:gr[x]){
            if(!vis[cx]) cnt++;
        }

        if(cnt==0) ans += pe[x]*lev[x];
        else{
            for(int cx:gr[x]){
                if(!vis[cx]){
                    q.push(cx);
                    vis[cx] = true;
                    lev[cx] = lev[x]+1;
                    pe[cx] = pe[x]*((double)1/cnt);
                }
            }
        }
        
    }

    cout<<fixed<<setprecision(15)<<ans<<endl;

}