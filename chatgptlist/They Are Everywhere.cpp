#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    set<char> st;
    for(char c:s) st.insert(c);
    int maxi = st.size();

    map<char,int> mp;
    int l=0,r=0,ans = n;
    while(r<n){

        mp[s[r]]++;
        while(l<=r && mp.size()>=maxi){

            if(mp.size()==maxi) ans = min(ans,r-l+1);
            if(mp[s[l]]>1) mp[s[l]]--;
            else mp.erase(s[l]);

            l++;
            
        }
        if(mp.size()==maxi) ans = min(ans,r-l+1);
        r++;
    }

    cout<<ans<<endl;

}