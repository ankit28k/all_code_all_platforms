#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        unordered_map<int,int> mp;

        int maxi=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            mp[arr[i]]++;
            maxi=max(maxi,arr[i]);
        }

        int ans=0;
        for(auto it:mp){
            ans = max(ans,it.second);
            int curr = it.first;

            int temp=0;
            if(curr%2 ==0){
                for(int i=4;i<=maxi;i=i*2){
                    int nxt = 0;
                    if(mp.find(curr+i) != mp.end()) nxt = mp[curr+i];
                    temp += nxt;

                }
            }
            else{
                for(int i=2;i<=maxi;i=i*2){
                    int nxt = 0;
                    if(mp.find(curr+i) != mp.end()) nxt = mp[curr+i];
                    temp += nxt;

                }
            }

            ans = max(ans,temp+it.second);

        }
        cout<<ans<<endl;
    }

}