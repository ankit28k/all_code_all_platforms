#include<bits/stdc++.h>
using namespace std;

long long fun(int idx,string prev,vector<pair<int ,string>>& arr,map<pair<int,string> , long long>& dp){

    if(idx==arr.size()) return 0;

    if(dp.find({idx,prev}) != dp.end()) return dp[{idx,prev}];

    string curr1 = arr[idx].second , curr2 = arr[idx].second;
    reverse(curr1.begin(),curr1.end());

    long long ans=1e18;

    if(prev == "-1" || curr2>=prev) {

        long long r=1e18  ,nr = 1e18;

        if(curr1>=prev) r = arr[idx].first + fun(idx+1,curr1,arr,dp);
        nr = fun(idx+1,curr2,arr,dp);

        ans = min( r, nr) ;
    }

    else if(curr2 < prev){
        
        // if(curr1 < prev) return dp[{idx,prev}] = 1e18;
        // else return dp[{idx,prev}] = arr[idx].first + fun(idx+1,curr1,arr,dp);

        if(curr1 >= prev) ans = min(ans,(long long)arr[idx].first + fun(idx+1,curr1,arr,dp));
    }

    return dp[{idx,prev}] = ans;

}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];


    vector<pair<int ,string>> arr(n);
    map<int,string> mp;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr[i] = {a[i],s};
        mp[i] = s;
    }
    
    map<pair<int,string> , long long> dp;

    mp[-1] = "-1";

    long long ans = fun(0,"-1",arr,dp);
    if(ans == 1e18) cout<<-1<<endl;
    else cout<<ans<<endl;
}