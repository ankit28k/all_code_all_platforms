#include<bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
    return a>b;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> uni(n),skill(n);
        for(int i=0;i<n;i++) cin>>uni[i];
        for(int i=0;i<n;i++) cin>>skill[i];

        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[uni[i]].push_back(skill[i]);
        }

        vector<long long> ans(n+1,0);

        for(auto it:mp){
            vector<int> temp = it.second;
            sort(temp.begin(),temp.end(),comp);

            int tn = temp.size();
            vector<long long> psum(tn);

            psum[0] = temp[0];
            for(int i=1;i<tn;i++) psum[i] = psum[i-1] + temp[i];

            for(int i=1;i<=tn;i++){
                ans[i] += psum[ tn - 1 - (tn%i) ];
            }
        }

        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;

    }

}