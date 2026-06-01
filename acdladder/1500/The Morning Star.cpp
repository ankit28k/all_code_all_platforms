#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);

        map<int,int> mx , my , mpdp , mpdn;

        for(int i=0;i<n;i++) {
            int x,y;
            cin>>x>>y;
            arr[i] = {x,y};

            mx[x]++;
            my[y]++;

            mpdp[y-x]++;
            mpdn[y+x]++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){

            int x = arr[i].first , y  = arr[i].second;
            // doing -1 to avoid self points 
            ans += mx[x] -1 ;
            ans += my[y] -1 ;

            ans += mpdp[y-x] -1 ;
            ans += mpdn[y+x] -1;

        }

        cout<<ans<<'\n';
    }

}