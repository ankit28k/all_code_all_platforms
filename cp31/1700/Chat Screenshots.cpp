#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(n)),gr(n+1);
        for(int i=0;i<k;i++) {
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }

        if(k==1) {
            cout<<"YES"<<endl;
            continue;
        }

        vector<int> ind(n+1,0),ans;
        for(int i=0;i<k;i++) {
            for(int j=1;j<n-1;j++){
                int x = arr[i][j],y=arr[i][j+1];
                gr[x].push_back(y);
                ind[y]++;
            }
        }

        queue<int> q;

        for(int i=1;i<=n;i++){
            if(ind[i]==0) q.push(i);
        }

        while(!q.empty()){
            int t= q.front();
            q.pop();

            ans.push_back(t);
            for(int cx:gr[t]){
                ind[cx]--;
                if(ind[cx]==0) q.push(cx);
            }
        }

        if(ans.size()==n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        

    }

}