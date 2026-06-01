#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        set<pair<int,int>> st;

        for(int i=0;i<m;i++) {
            int x,y;
            cin>>x>>y; 
            if(st.find({x,y}) == st.end()) st.insert({x,y});
            if(st.find({y,x}) == st.end()) st.insert({y,x});
        }

        int temp=1 ;
        long long ans =0;
        for(int i=2;i<=n;i++){
            
            if(st.find({i,i-1}) == st.end()) temp++;

            else{
                if(temp>1)ans += 1LL*(temp-1)*(temp)/2;
                temp =1;
            }
        }

        if(temp>1) ans += 1LL*(temp-1)*(temp)/2;

        cout<<ans+n<<endl;

    }

}