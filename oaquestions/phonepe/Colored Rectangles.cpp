#include <bits/stdc++.h>
using namespace std;


long long fun(int r,int g,int b,vector<int>& red, vector<int>& gr,vector<int>& bl,vector<vector<vector<long long>>>& dp) {

    int nr = red.size() , nb = bl.size() , ng = gr.size();
    if(r==nr && b==nb || r==nr && g==ng || g==ng && b==nb) return 0; // if any 2 become out of bound or exhausted....we cant take any one

    if(dp[r][g][b] != -1) return dp[r][g][b];
    long long ans=0;
    if(r<nr && b<nb){
        long long temp = 1LL*red[r]*bl[b] + fun(r+1,g,b+1,red,gr,bl,dp);
        ans = max(ans,temp);
    }
    if(r<nr && g<ng){
        long long temp = 1LL*red[r]*gr[g] + fun(r+1,g+1,b,red,gr,bl,dp);
        ans = max(ans,temp);
    }
    if(g<ng && b<nb){
        long long temp = 1LL*gr[g]*bl[b] + fun(r,g+1,b+1,red,gr,bl,dp);
        ans = max(ans,temp);
    }
    return dp[r][g][b] = ans;

}
int main() {
    int r,g,b;
    cin>>r>>g>>b;

    vector<int> red(r) ,gr(g) , bl(b);
    for(int i=0;i<r;i++) cin>>red[i];
    for(int i=0;i<g;i++) cin>>gr[i];
    for(int i=0;i<b;i++) cin>>bl[i];

    sort(red.rbegin() , red.rend());
    sort(gr.rbegin() , gr.rend());
    sort(bl.rbegin() , bl.rend());
    
    // as one can exhaust like fun(nr,_,_) but rest 2 can keep going on...so need store dp[r][][]....hence +1 for all
    vector<vector<vector<long long>>> dp(r+1,vector<vector<long long>>(g+1,vector<long long>(b+1,-1))); 
    long long ans=fun(0,0,0,red,gr,bl,dp);
    cout<<ans<<endl;
}