#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> gr(n+1);

    vector<int> ind(n+1,0);

    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
        ind[a]++;
        ind[b]++;
    }

    
    queue<int> q1;
    vector<int> vis1(n+1,false);
    vector<int> level1(n+1,0);

    q1.push(1);
    vis1[1] = true;
    while(!q1.empty()){
        int x = q1.front();
        q1.pop();

        for(int cx:gr[x]){
            if(!vis1[cx]){
                vis1[cx] = true;
                q1.push(cx);
                level1[cx] = level1[x]+1;
            }
        }
    }

    vector<bool> indus(n+1,false) ;


    vector<pair<int,int>> temp;
    for(int i=1;i<=n;i++){
        temp.push_back({level1[i],i});
    }

    sort(temp.rbegin(),temp.rend());

    
    for(int i=0;i<temp.size();i++){
        int idx = temp[i].second;
        if(ind[idx]==1 && idx != 1){
            q1.push(idx);
            indus[idx] = true;
            k--;
            if(k==0) break;
        }
    }

    
    while(k>0 && !q1.empty()){
        int x = q1.front();
        q1.pop();

        for(int cx:gr[x]){
            ind[cx]--;
            if(ind[cx]==1) {
                q1.push(cx);
                indus[cx]=true;
                k--;
                if(k==0) break;
            }
        }
    }
    

    vector<int> level(n+1,0);
    vector<bool> vis(n+1,false);

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int cx:gr[x]){
            if(!vis[cx]){
                vis[cx] = true;
                q.push(cx);
                if(indus[x]) level[cx] = level[x];
                else level[cx] = level[x]+1;
            }
        }
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        if(indus[i]) ans+= level[i];
    }

    cout<<ans<<endl;

}