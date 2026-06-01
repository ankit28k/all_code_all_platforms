#include<bits/stdc++.h>
using namespace std;

pair<int,int> fun(vector<int>& neigh,int n){

    int a=-1,b=-1,fa=0,fb=0;

    for(int i=1;i<=n;i++){
        if(neigh[i]==1) continue;

        if(a== -1 && b== -1){
            a = neigh[i];
        }

        else if(neigh[i] != a && b== -1){
            b = neigh[i];
        }

        if(neigh[i]==a) fa++;
        else if(neigh[i]==b) fb++;

    }

    //if(a==-1) return {b,b-1}; //as high chances b will be -1
    if(b==-1) return {a,a-1};

    if(fa==1){
        return {a,b-1};
    }

    if(fb==1){
        return {b,a-1};
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        // vector<vector<int>> graph(n+1);
        vector<int> neigh(n+1,0);

        for(int i=0;i<m;i++) {
            int a,b;
            cin>>a>>b;
            // graph[a].push_back(b);
            // graph[b].push_back(a);
            neigh[a]++;
            neigh[b]++;
        }
        
        pair<int,int> ans  = fun(neigh,n);
        cout<<ans.first<<" "<<ans.second<<endl;


    }

}