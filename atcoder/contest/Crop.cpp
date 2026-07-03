#include<bits/stdc++.h>
using namespace std;

bool allrowzero(vector<vector<char>>& arr,int row,int stc,int endc) {
    for(int j=stc;j<=endc;j++) {
        if(arr[row][j]!='.') return false;
    }
    return true;
}

bool allcolzero(vector<vector<char>>& arr,int col,int str,int endr) {
    for(int i=str;i<=endr;i++) {
        if(arr[i][col]!='.') return false;
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }

    int str=0,stc=0,endr=n-1,endc=m-1;
    while(str<=endr && stc<=endc) {
        if(allrowzero(arr,str,stc,endc)) str++;
        else if(allrowzero(arr,endr,stc,endc)) endr--;
        else if(allcolzero(arr,stc,str,endr)) stc++;
        else if(allcolzero(arr,endc,str,endr)) endc--;
        else break;
    }   

    for(int i=str;i<=endr;i++) {
        for(int j=stc;j<=endc;j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}