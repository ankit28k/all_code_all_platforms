#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int b,g,k;
        cin>>b>>g>>k;
        vector<int> boy(k)  , girl(k);
        for(int i=0;i<k;i++) cin>>boy[i];
        for(int i=0;i<k;i++) cin>>girl[i];

        map<int,vector<int>> mp;
        map<int,int> mpboy;

        for(int i=0;i<k;i++){
            mp[girl[i]].push_back(boy[i]);
        }

        long long total =0 , ans =0;

        for(auto it = mp.rbegin();it!=mp.rend();it++){
            vector<int>& temp = it->second;

            int nt = temp.size();
            int cnt=0;
            for(int i=0;i<nt;i++){
                cnt++;
                ans += total - mpboy[temp[i]];
                mpboy[temp[i]]++;
            }

            total+=cnt;

        }

        cout<<ans<<endl;


    }

}