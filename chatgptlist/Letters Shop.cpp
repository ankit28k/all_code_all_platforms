#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    string s;
    cin>>s;

    vector<vector<int>> fqs(26,vector<int>(n,0));

    int f = s[0]-'a';
    fqs[f][0] =1;

    for(int i=1;i<n;i++){

        int val = s[i]-'a';

        for(int j=0;j<26;j++){

            if(j==val) fqs[j][i] = 1+fqs[j][i-1];
            else fqs[j][i] = fqs[j][i-1];
        }
    }

    cin>>m;
    while(m--){
        string t;
        cin>>t;
        int nt = t.length();

        vector<int> fqt(26,0);
        for(int i=0;i<nt;i++) fqt[t[i]-'a']++;

        int ans =0;
        for(int i=0;i<26;i++){

            vector<int>& temp = fqs[i];

            int idx = lower_bound(temp.begin(),temp.end(),fqt[i]) - temp.begin();
            ans = max(ans,idx);
        }

        cout<<ans+1<<endl;
    }
    

}