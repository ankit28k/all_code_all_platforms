#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,k,d;
    cin>>n>>k>>d;

    queue<int> q;
    vector<bool> vis(n+1,false);

    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        if(!vis[x]) {
            q.push(x);
            vis[x]=true;
        }
    }
    //prevent tle ...rather using set....and duplication can give wrong answers
    // for(int i=0;i<k;i++){
    //     int x;
    //     cin>>x;
    //     q.push(x);
    //     vis[x]=true;
    // }


    //gives tle
    // vector<vector<int>> gr(n+1);
    // map<pair<int,int> , int> mp;
    //set<int> ans;

    // for(int i=0;i<n-1;i++) {
    //     int a,b;
    //     cin>>a>>b;
    //     gr[a].push_back(b);
    //     gr[b].push_back(a);
    //     mp[{a,b}] = i+1;
    // }

    vector<vector<pair<int,int>>> gr(n+1);

    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back({b,i+1});
        gr[b].push_back({a,i+1});
    }

    vector<int> level(n+1,0);
    vector<bool> added(n,false);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto it:gr[x]){
            int cx = it.first , idx = it.second;

            if(!vis[cx]){
                q.push(cx);
                level[cx] = level[x]+1;
                vis[cx] = true;
            }
            //gives tle
            // else if(vis[cx] && level[x]<=level[cx]){
            //     if(mp.find({x,cx}) != mp.end()) ans.insert(mp[{x,cx}]);
            //     if(mp.find({cx,x}) != mp.end()) ans.insert(mp[{cx,x}]);
            // }

            else if(vis[cx] && level[x]<=level[cx]){
                added[idx] = true;
            }
            
        }
    }

    int cnt=0;
    vector<int> ans;
    for(int i=1;i<n;i++) {
        if(added[i]) {
            cnt++;
            ans.push_back(i);
        }
    }

    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;

}