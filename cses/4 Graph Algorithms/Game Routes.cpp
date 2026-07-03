#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> gr(n+1);
    vector<int> ways(n+1,0) , ind(n+1,0);

    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        ind[b]++;
    }

    

    ways[1]=1;
    queue<int> q;

    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int cx:gr[x]){
            ways[cx] = (ways[cx] + ways[x])%mod;
            ind[cx]--;

            if(ind[cx]==0) q.push(cx);
        }
    }

    cout<<ways[n]<<endl;

}