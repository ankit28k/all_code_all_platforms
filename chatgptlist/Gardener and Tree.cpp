#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
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

        vector<int> level(n+1,1);
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(ind[i]==1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int x = q.front();
            q.pop();

            for(int cx:gr[x]){

                ind[cx]--;
                if(ind[cx]==1) {
                    q.push(cx);
                    level[cx] = level[x]+1;
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            if(level[i]>k) ans++;
        }

        cout<<ans<<endl;
        
    }

}