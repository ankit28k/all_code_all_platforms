#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> m;
        for(int i=1;i<=n;i++) {
            int x ;
            cin>>x;
            m[x - i]++; //aj - j == ai - i
        }

        long long ans=0;
        for(auto it = m.begin() ; it!= m.end(); it++){
            int cnt = it->second;
            ans += 1LL*cnt*(cnt-1)/2; // nC2
        }

        cout<<ans<<endl;
    }

}