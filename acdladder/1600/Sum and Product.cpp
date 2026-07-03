#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,long long> mp;

        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            mp[x]++;
        }

        int q;
        cin>>q;
        vector<long long> ans;
        while(q--){
            long long x,y;
            cin>>x>>y;

            long long d = x*x - 4*y , val1 = 1e18,val2 = 1e18;
            if(d>=0) {
                long long sq = sqrtl(d);
                if(sq*sq == d && (x + sq)%2 ==0 && (x-sq)%2==0){
                    val1 = (x + sqrt(x*x - 4*y))/2;
                    val2 = (x - sqrt(x*x - 4*y))/2;
                }
                
            }

            long long t=0;
            if(val1 != 1e18 && val2 != 1e18){

                if(val1 == val2){
                    long long fval1 = mp[val1];
                    t = fval1*(fval1-1)/2;
                }
                else{
                    long long fval1 = mp[val1];
                    long long fval2 = mp[val2];
                    t = fval1*fval2;
                }
                
               
            }
            
            ans.push_back(t);
        }

        for(auto x:ans) cout<<x<<" ";
        cout<<endl;

    }

}