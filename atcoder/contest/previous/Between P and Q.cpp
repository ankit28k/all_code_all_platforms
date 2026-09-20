#include <bits/stdc++.h>
using namespace std;

long long fact[11];

long long rper(vector<int>& p) {
    int n = p.size();
    vector<int> us(n+1,0);

    long long rank=0;

    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int x=1;x<p[i];x++) {
            if(!us[x]) cnt++;
        }
        rank += 1LL*cnt*fact[n-i-1];
        us[p[i]]=1;
    }

    return rank;
}

int main() {
    int n;
    cin>>n;

    vector<int> p(n),q(n);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];

    fact[0]=1;
    for(int i=1;i<=10;i++) fact[i] = fact[i-1]*i;

    long long r1 = rper(p);
    long long r2 = rper(q);

    cout<<max(0LL,r2-r1-1)<<endl;
}