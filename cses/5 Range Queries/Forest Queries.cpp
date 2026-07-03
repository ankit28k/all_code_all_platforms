#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<char>> arr(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> psum(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i-1][j-1]=='*') psum[i][j] = 1 + psum[i-1][j] + psum[i][j-1] -psum[i-1][j-1];
            else psum[i][j] = psum[i-1][j] + psum[i][j-1] -psum[i-1][j-1];
        }
    }

    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<psum[y2][x2] - psum[y1 - 1][x2] - psum[y2][x1 - 1] + psum[y1 - 1][x1 - 1]<<endl;
        //cout<<psum[x2][y2] + psum[x1-1][y2] - psum[x2][y1-1] - psum[x1-1][y1-1]<<endl;
        // whole sum till x2,y2..remove top part...remove left part.....add the part removed twice
    }




}