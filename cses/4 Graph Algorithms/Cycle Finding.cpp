#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<long long>> edges(m);
    for(int i=0;i<m;i++) {
        long long x,y,wt;
        cin>>x>>y>>wt;
        edges[i] = {wt,x,y};
    }

    vector<long long> dist(n+1,0); //as no starting node present
    vector<int> par(n+1,-1);

    for(int j=0;j<n-1;j++){
        for(int i=0;i<m;i++){
            long long wt = edges[i][0] , x = edges[i][1] , y = edges[i][2];

            if(dist[x]+wt<dist[y]){
                dist[y] = dist[x] + wt;
                par[y] = x;
            }
        }
    }

    int st=-1;
    for(int i=0;i<m;i++){
        long long wt = edges[i][0] , x = edges[i][1] , y = edges[i][2];

        if(dist[x]+wt<dist[y]){
            st = x;
            par[y]=x;
            break;
        }
    }

    if(st==-1) cout<<"NO"<<endl;
    else{
        vector<int> ans;

        /*
        ===================================================================================
        THE "DOWNSTREAM TAIL" TRAP (Why we must walk backward N times)
        ===================================================================================

        THE PROBLEM: 
        Bellman-Ford detects a negative cycle by finding an edge that gets cheaper on the 
        N-th pass. However, the edge that triggers the alarm is NOT always inside the cycle. 
        Sometimes, it is on a "tail" pointing AWAY from the cycle.

        THE ANALOGY (The Discount Chain Reaction):
        A negative cycle is a discount machine. When nodes inside the cycle get cheaper, 
        they pass those discounts down to any nodes connected to them, even if those 
        connected nodes are in a straight line (a tail).

        EXAMPLE GRAPH (N = 4):
            [1] <---> [2]      (The Negative Cycle: drops by -10 each pass)
                    |
                    v
                    [3]      (The Tail: gets discounts from Node 2)
                    |
                    v
                    [4]      (The Tail: gets discounts from Node 3)

        THE TRAP:
        1. On the N-th pass, the cycle makes Node 2 cheaper. 
        2. Because 2 is cheaper, 3 gets cheaper. Because 3 is cheaper, 4 gets cheaper.
        3. The algorithm evaluates edge 3 -> 4, sees it is cheaper, and sounds the alarm!
        4. It sets `st = 3` (the start of the edge that triggered the alarm).

        WHY A NORMAL 'WHILE' LOOP CRASHES HERE:
        If we try to trace the cycle starting from Node 3, we ask for parents:
        - Parent of 3 is 2.
        - Parent of 2 is 1.
        - Parent of 1 is 2.
        - Parent of 2 is 1...
        We are now spinning backwards in the 1-2 loop forever. The loop is waiting to see 
        Node 3 again to close the circle, but Node 3 is a dead-end pointing AWAY from the 
        loop. We get an infinite loop (Time Limit Exceeded).

        THE FIX: 
            for(int i = 0; i < n; i++) st = par[st];

        Before we start recording our answer, we force our pointer to walk backward 
        exactly N times. 
        - Step 1: st = par[3]  -> st becomes 2
        - Step 2: st = par[2]  -> st becomes 1
        - Step 3: st = par[1]  -> st becomes 2
        - Step 4: st = par[2]  -> st becomes 1

        Because the maximum length of any straight tail is N-1, taking N steps backward 
        MATHEMATICALLY GUARANTEES we walk backward completely off the fake tail and drop 
        safely into the actual spinning cycle. Now we can safely record the cycle!
        ===================================================================================
        */
        for(int i=0;i<n;i++) st = par[st];


        int t = st;
        while(true){
           if(par[t] != st){
            ans.push_back(t);
            t = par[t];
           } 

           else{
            ans.push_back(t);
            ans.push_back(st);
            break;
           }
        }

        reverse(ans.begin(),ans.end());
        cout<<"YES"<<endl;
        for(int x:ans) cout<<x<<" ";
        cout<<endl; 
    }


}