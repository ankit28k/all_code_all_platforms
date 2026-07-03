#include<bits/stdc++.h>
using namespace std;

long long fun(long long x,long long y,long long a,long long b){
    long long d = min(2*a,2*b) , s = min({a+b,4*a,4*b});
    return min(x,y)*d + abs(y-x)*s/2;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,dstx,dsty;
        cin>>a>>b>>dstx>>dsty;

        long long dx = abs(dstx) , dy = abs(dsty);
        int xodd = (dx+1)/2 , xeven = dx/2;
        int yodd = (dy+1)/2 , yeven = dy/2;

        int ans = xodd*a + xeven*b + yodd*b + yeven*a;


        // vector<pair<int,pair<int,int>>> move = {
        //     {0,{-1,0}} , {0,{1,0}}, //hori
        //     {1,{0,1}} , {1,{0,-1}} //vert
        // };

        // set<pair<int,int>> vis;

        // queue< pair< pair<int,int> , pair<int,int> >> q;
        // q.push({{0,0} , {0,0}}); // 0 for odd parity , 1 for even...k
        // vis.insert({0,0});

        // int ans=-1;

        // while(!q.empty()){
        //     auto top = q.front();
        //     q.pop();

        //     int x = top.first.first , y = top.first.second;
        //     int iseven = top.second.first , cost = top.second.second;

        //     if(x==dstx && y == dsty) {
        //         ans = cost;
        //         break;
        //     }

        //     for(auto mov:move){
        //         int isver = mov.first;
        //         int cx = x+mov.second.first , cy = y+mov.second.second;

        //         int ncost;
        //         if(iseven ==1 && isver ==1) ncost = a;
        //         else if(iseven ==1 && isver ==0) ncost = b;
        //         else if(iseven ==0 && isver ==1) ncost = b;
        //         else if(iseven ==0 && isver ==0) ncost = a;

        //         if(vis.find({cx,cy}) == vis.end()){
        //             vis.insert({cx,cy});
        //             q.push({{cx,cy},{1-iseven , ncost}});
        //         }
        //     }
        // }

        // cout<<ans<<endl;
    }

}