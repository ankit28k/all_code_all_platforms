#include<bits/stdc++.h>
using namespace std;

// bool isprime(int n){
//     if(n<=1) return false;
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0) return false;
//     }
//     return true;
// }

vector<bool> isprime(3e5+1,true);

//void putdivisors(map<int,vector<int>>& mp,int idx,int val){
void putdivisors(vector<vector<int>>& mp,int idx,int val){

    for(int i=1;i*i<=val;i++){
        if(val%i==0){
            if((val/i) != i){
                if(isprime[i]) mp[idx].push_back(i);
                if(isprime[val/i]) mp[idx].push_back(val/i);
            }
            else {
                if(isprime[i]) mp[idx].push_back(i);
            }
        }
    }
}
int main(){

    isprime[0] = false;
    isprime[1] = false;
    for(int i=2;i<=3e5;i++){
        if(isprime[i]){
            for(int j=i*2;j<=3e5;j+=i){
                isprime[j] = false;
            }
        }
    }

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    //map<int,vector<int>> mp_idx_to_div , mp_divisor_to_idx;
    vector<vector<int>> mp_idx_to_div(n) ;
    vector<vector<int>> mp_divisor_to_idx(3e5);

    for(int i=0;i<n;i++){
        putdivisors(mp_idx_to_div,i,arr[i]);
    }

    // for(auto it:mp_idx_to_div){
    //     vector<int>& temp = it.second;
    //     for(int x:temp){
    //         mp_divisor_to_idx[x].push_back(it.first);
    //     }
    // }

    for(int i=0;i<n;i++){
        vector<int>& temp = mp_idx_to_div[i];
        for(int x:temp){
            mp_divisor_to_idx[x].push_back(i);
        }
    }

    int s,t;
    cin>>s>>t;

    s--;
    t--;

    vector<int> par(n,-1);
    vector<int> lev(n,1);
    vector<bool> vis(n,false);

    //Add a visited array for prime factors
    vector<bool> vis_prime(3e5,false);

    queue<int> q;
    q.push(s);
    vis[s] = true;

    
    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(vis[t]) break;
        for(auto it:mp_idx_to_div[x]){
            
            // FIX: If we already expanded this prime, skip it to avoid O(N^2) TLE
            if(vis_prime[it]) continue;
            vis_prime[it] = true;
            
            for(auto cx: mp_divisor_to_idx[it]){
                if(!vis[cx]){
                    vis[cx] =  true;
                    par[cx] = x;
                    lev[cx] = lev[x]+1;
                    q.push(cx);
                }
            }
            if(vis[t]) break;
        }

    }  

    if(!vis[t]){
        cout<<-1<<endl;
        return 0;
    }

    vector<int> path;

    int k = t;
    path.push_back(k);
    while(par[k] != -1){
        path.push_back(par[k]);
        k = par[k];
    }

    reverse(path.begin(),path.end());
    cout<<lev[t]<<endl;
    for(int x:path) cout<<x+1<<" ";
    cout<<endl;




}