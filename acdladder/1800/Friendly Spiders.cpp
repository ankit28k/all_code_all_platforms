#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)  cin>>arr[i];
    

    vector<vector<int>> gr(n+1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(gcd(arr[i],arr[j]) != 1){
                gr[i+1].push_back(j+1);
                gr[j+1].push_back(i+1);
            }
        }
    }

    int s,t;
    cin>>s>>t;

    vector<int> par(n+1,-1);
    vector<bool> vis(n+1,false);
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == t) break;

        for(auto cx:gr[x]){
            if(!vis[cx]){
                vis[cx] = true;
                q.push(cx);
                par[cx] = x;
            }
        }
    }

    if(vis[t]==false) {
        cout<<-1<<endl;
        return 0;
    }
    vector<int> ans;
    ans.push_back(t);
    
    while(par[t] != -1){
        t = par[t];
        ans.push_back(t);
    }

    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
    

}