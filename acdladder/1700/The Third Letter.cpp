#include<bits/stdc++.h>
using namespace std;

string fun(int src,vector<vector<pair<int,long long>>>& arr,map<int,long long>& mp,int n){

    mp[src] =0;

    queue<pair<int,long long>> q;

    q.push({src,0});

    while(!q.empty()){
        auto top = q.front();
        q.pop();

        int x = top.first ;
        long long pos = top.second;

        for(auto it:arr[x] ){
            int y = it.first ;
            long long d = it.second;

            long long posy = pos + d;

            if(mp.find(y) != mp.end()){
                if(mp[y] != posy) return "NO";
            }

            else {
                mp[y] = posy;
                q.push({y,posy});
            }
        }
    }

    return "YES";

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,long long>>> arr(n+1);
        for(int i=0;i<m;i++) {
            int x,y;
            long long d;
            cin>>x>>y>>d;
            arr[x].push_back({y,d});

            /* * WHY WE NEED THIS REVERSE EDGE:
             * The conditions describe a mutual relationship, not a one-way street. 
             * If soldier X is 'd' meters relative to Y, then Y is '-d' meters relative to X.
             * * Example Failure Without It:
             * Input: 3 soldiers, 2 conditions: (2->1 at 10m) and (2->3 at 20m).
             * If we only store forward edges (arr[2] has 1 and 3) but arr[1] is empty:
             * - The main loop starts at i = 1. BFS [Breadth-First Search] runs for node 1, 
             * sets mp[1] = 0, and stops instantly because it has no outgoing edges.
             * - The main loop moves to i = 2. BFS runs for node 2, sets mp[2] = 0. 
             * It then checks node 1, expects it to be at 0 + 10 = 10. 
             * But mp[1] is already 0! It falsely returns "NO".
             * * By adding the reverse edge, node 1 can "look backward" and see it is 
             * attached to node 2. This guarantees the entire connected camp is mapped 
             * onto a single, shared coordinate system in one continuous traversal, 
             * preventing artificial splits and fake contradictions.
             */
            arr[y].push_back({x,-d});
        }

        map<int,long long> mp;
        string ans ="YES";

        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()) {
                string temp = fun(i,arr,mp,n);
                if(temp =="NO") {
                    ans = "NO";
                    break;
                }
            }
        }

        cout<<ans<<endl;
        
    }

}