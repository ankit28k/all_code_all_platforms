#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<int> distinct_r(n) , distinct_l(n);
        unordered_set<char> sl , sr;

        for(int i=0;i<n;i++) {
            sl.insert(s[i]);
            distinct_l[i] = sl.size();
        }

        for(int i=n-1;i>=0;i--) {
            sr.insert(s[i]);
            distinct_r[i] = sr.size();
        }

        int ans = 2;
        for(int i=0;i<n-1;i++){
            ans = max(ans,distinct_l[i]+distinct_r[i+1]);
        }

        cout<<ans<<endl;


    }

}