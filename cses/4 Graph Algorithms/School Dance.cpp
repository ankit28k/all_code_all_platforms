#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    map<int,vector<int>> mb;
    for(int i=0;i<k;i++) {
        int x,y;
        cin>>x>>y;
        mb[x].push_back(y);
    }
    map<int,int> mg;

    long long ans=0,total=0;
    for(auto it = mb.rbegin();it!=mb.rend();it++){
        vector<int>& temp = it->second;

        int nt= temp.size(),cnt=0;
        for(int i=0;i<nt;i++){
            cnt++;
            ans += total - mg[temp[i]];
            mg[temp[i]]++;
        }

        total += cnt;

    }

    cout<<ans<<endl;

}