#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,d;
    cin>>m>>d;
    
    vector<int> lev(m,1e9);
    queue<int> q;
    for(int i=0;i<m;i++){
        char c;
        cin>>c;
        if(c=='G') {
            q.push(i);
            lev[i]=0;
        }
    }

    vector<int> move = {1,-1};
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int mov : move){
            int cx = x+mov;
            if(lev[cx]>lev[x]+1){
                lev[cx] = lev[x]+1;
                q.push(cx);
            }
        }
    }

    int ans=0;
    for(int i=0;i<m;i++){
        if(lev[i]>d) ans++;
    }
    cout<<ans<<endl;
    

}