#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<vector<int>> gr(n+1);
    vector<int> ind(n+1,0);
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
        ind[a]++;
        ind[b]++;
    }

    

}