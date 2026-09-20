#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int,int>> edges(n+1);
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        edges[i]= {a,b};
    }

}