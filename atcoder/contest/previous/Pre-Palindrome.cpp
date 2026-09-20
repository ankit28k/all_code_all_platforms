#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;

    int n=s.size();
    long long ans=0;

    //odd len
    for(int i=0;i<n;i++) {
        int l=i,r=i;
        int diff=0;

        while(l>=0 && r<n) {
            if (s[l]!=s[r]) diff++;
            if (diff>1) break;
            ans++;
            l--;
            r++;
        }
    }
    //even len
    for(int i=0;i<n-1;i++) {
        int l=i,r=i+1;
        int diff=0;

        while(l>=0 && r<n) {
            if (s[l]!=s[r]) diff++;
            if (diff>1) break;
            ans++;
            l--;
            r++;
        }
    }

    cout<<ans<<endl;
}