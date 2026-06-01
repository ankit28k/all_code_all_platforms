#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<int> prev(k+1,-1);
        map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i - prev[arr[i]] - 1);
            prev[arr[i]] = i;
        }

        for(auto it:mp){
            int val = it.first;

            mp[val].push_back(n-1 - prev[val]); 
        }

        int ans = INT_MAX;
        for(auto it:mp){
            vector<int> temp = it.second;
            sort(temp.begin(),temp.end());

            int nt = temp.size();
            int newmaxgap = temp[nt-1]/2; 

            int maxval ;
            if(nt>1) maxval = max(newmaxgap,temp[nt-2]);
            else maxval = newmaxgap;

            ans = min(ans,maxval);
        }

        cout<<ans<<endl;
    }

}