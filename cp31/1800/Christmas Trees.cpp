#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;

    vector<long long> arr(n);
    queue<long long> q;
    unordered_map<long long,long long> srcs;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        q.push(arr[i]);
        srcs[arr[i]]=0;
    }

    vector<int> move = {-1,1};
    unordered_map<long long,long long> vis;
    
    while(vis.size() <m && !q.empty()){
        long long x= q.front();
        q.pop();

        for(int mov:move){
            long long cx = mov+x;
            if(vis.find(cx)==vis.end() && srcs.find(cx)==srcs.end()){
                q.push(cx);
                if(srcs.find(x) != srcs.end()) vis[cx] = 1;
                else vis[cx] = vis[x]+1;

                if(vis.size()==m) break;
            }
            
        }
        if(vis.size()==m) break;
    }

    long long sum=0;
    for(auto x:vis) sum+=x.second;
    cout<<sum<<endl;
    for(auto x:vis) cout<<x.first<<" ";
    cout<<endl;
}