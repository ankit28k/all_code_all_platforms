#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    long long w,h;
    cin>>w>>h;

    int d;
    cin>>d;
    vector<long long> dcorr(d);
    for(int i=0;i<d;i++) cin>>dcorr[i];

    int u;
    cin>>u;
    vector<long long> ucorr(u);
    for(int i=0;i<u;i++) cin>>ucorr[i];

    int l;
    cin>>l;
    vector<long long> lcorr(l);
    for(int i=0;i<l;i++) cin>>lcorr[i];

    int r;
    cin>>r;
    vector<long long> rcorr(r);
    for(int i=0;i<r;i++) cin>>rcorr[i];

    // sort(dcorr.begin(),dcorr.end());
    // sort(ucorr.begin(),ucorr.end());
    // sort(lcorr.begin(),lcorr.end());
    // sort(rcorr.begin(),rcorr.end());

    long long ans = INT_MIN;

    long long t1 = abs(lcorr[0] - lcorr[l-1])*w;
    ans = max(ans,t1);

    long long t2 = abs(rcorr[0] - rcorr[r-1])*w;
    ans = max(ans,t2);

    long long t3 = abs(ucorr[0] - ucorr[u-1])*h;
    ans = max(ans,t3);

    long long t4 = abs(dcorr[0] - dcorr[d-1])*h;
    ans = max(ans,t4);

    cout<<ans<<endl;

  }
}