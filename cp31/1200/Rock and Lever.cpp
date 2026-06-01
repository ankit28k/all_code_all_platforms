#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> m;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;

            int msb = log2(x); // Find the position of the most significant bit (0-indexed)
            m[msb]++;
        }

        long long ans = 0;
        for(auto it = m.begin(); it!= m.end(); it++){
            int msb = it->second;
            ans += 1LL*msb*(msb-1)/2; // nC2
        }

        cout<<ans<<endl;

         
    }

}