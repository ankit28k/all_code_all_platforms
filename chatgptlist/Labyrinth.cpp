#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,m,srcx,srcy,maxl,maxr;
    cin>>n>>m>>srcx>>srcy>>maxl>>maxr;
    
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    srcx--;
    srcy--;

    vector<pair<int,int>> moveud = {{-1,0} , {1,0}};
    vector<pair<int,int>> movelr = {{0,-1} , {0,1}};

    vector<vector<int>> dist(n,vector<int>(m,1e9));
    queue<vector<int>> q;
    q.push({srcx,srcy,maxl,maxr});
    dist[srcx][srcy]=0;

    while(!q.empty()){
        auto top = q.front();
        q.pop();

        int x = top[0] , y = top[1] , leftl =top[2] , leftr = top[3];
        for(auto mov:moveud){
            int cx = x+mov.first , cy = y+ mov.second;
            if(cx>=0 && cy>=0 && cx<n && cy<m && arr[cx][cy]=='.'){
                q.push({cx,cy,leftl,leftr});
            }
        }

        if(leftl<=0 && leftr<=0) continue;

        for(auto mov:movelr){
            int cx = x+mov.first , cy = y+mov.second;

            if(cx>=0 && cy>=0 && cx<n && cy<m && arr[cx][cy]=='.'){

                if(mov.second==1 && leftr>0){
                    q.push({cx,cy,leftl,leftr-1});
                }
                else if(mov.second==-1 && leftl>0){
                    q.push({cx,cy,leftl-1,leftr});
                }
                
            }
        }

    }

    int cnt=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
        }
    }
    cout<<cnt<<endl;
    

}