#include <bits/stdc++.h>
using namespace std;


//no need of dijksta as....Manhattan distance satisfies the triangle inequality for any three points A, X, M: => dist(A,M)≤dist(A,X)+dist(X,M)
// => find major city which is closest to dst / src .....and add them 2 to get min dist as major cities in-between distance is 0


int main(){

  int t;
  cin>>t;
  while(t--){
    int n,k,a,b;
    cin>>n>>k>>a>>b;

    a--; // convert to 0-based
    b--;
    
    vector<pair<long long,long long>> grid(n);
    
    for(int i=0;i<n;i++) {
      int x,y;
      cin>>x>>y;
      grid[i].first = x;
      grid[i].second = y;
    }

    long long src_x = grid[a].first ,src_y = grid[a].second ,dst_x = grid[b].first, dst_y = grid[b].second;
    long long ans = llabs(src_x - dst_x) + llabs(src_y - dst_y);

    if(k>0){
      long long dist_a = LLONG_MAX , dist_b = LLONG_MAX;

      for(int i=0;i<k;i++){
        long long x = grid[i].first , y = grid[i].second;

        long long d_a = llabs(src_x - x) + llabs(src_y - y);
        long long d_b = llabs(x - dst_x) + llabs(y - dst_y);

        dist_a = min(dist_a,d_a);
        dist_b = min(dist_b,d_b);

        ans = min(ans , dist_a + dist_b);

      }
    }

    cout<<ans<<endl;

    // vector<vector<pair<long long,int>>> graph(n);

    // vector<bool> vis(n,false) , major(n,false);

    // for(int i=0;i<k;i++) major[i] = true;

    // for(int i=0;i<n;i++){
    //   for(int j = i+1;j<n;j++){
    //     int x1 = grid[i].first , y1 = grid[i].second;
    //     int x2 = grid[j].first , y2 = grid[j].second;

    //     long long wt;

    //     if(major[i] && major[j]) wt =0;
    //     else wt = llabs(x1-x2) + llabs(y1-y2);

    //     graph[i].push_back({wt,j});
    //     graph[j].push_back({wt,i});
    //   }
    // }

    // vector<long long> dist(n,LLONG_MAX);

    // set<pair<long long,int>> pq;

    // dist[a] = 0;
    // pq.insert({0,a});

    // while(!pq.empty()){

    //   auto top = *(pq.begin());
            
    //   long long distance = top.first;
    //   int node = top.second;
            
    //   pq.erase(top);
            
    //   for(auto it : graph[node]){
                
    //     long long edgewt = it.first;
    //     int adjnode = it.second;
                
    //     if(edgewt + distance < dist[adjnode]){
                    
    //         if(dist[adjnode] != LLONG_MAX) pq.erase({dist[adjnode],adjnode});
                      
    //         dist[adjnode] = edgewt + distance;
    //         pq.insert({ dist[adjnode], adjnode });
    //       }
    //   }
    // }

    // cout<<dist[b]<<endl;
    
  }
}