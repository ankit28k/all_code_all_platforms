#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        vector<int> dis(k),time(k);
        for(int i=0;i<k;i++) cin>>dis[i];
        for(int i=0;i<k;i++) cin>>time[i];

        
        vector<pair<int,int>> queries(q);
        for(int i=0;i<q;i++) {
            int x;
            cin>>x;
            queries[i] = {x,i};
        }

        sort(queries.begin(),queries.end());
        vector<long long> ans(q);
        vector<long long> arr(k);

        int j=0,cq=0;
        while(cq<q && queries[cq].first==0){
            ans[queries[cq].second]=0;
            cq++;
        }

        while(j<k){

            int cpos = dis[j] , prpos=0;
            if(j>0) prpos = dis[j-1];
            int ctime = time[j] , prtime = 0;
            if(j>0) prtime = time[j-1];

            // int speed = (cpos - prpos)/(ctime - prtime);
            int num = (cpos - prpos);
            int den = (ctime - prtime);

            while(cq<q && queries[cq].first<=cpos){
                long long temp = prtime + 1LL*(queries[cq].first - prpos)*den/num;
                ans[queries[cq].second] = temp;
                cq++;
            }
            j++;

        }

        for(int x:ans) cout<<x<<" ";
        cout<<endl;
    }
    

}