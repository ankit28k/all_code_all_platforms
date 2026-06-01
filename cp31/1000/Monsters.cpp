#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second <b.second;
    return a.first>b.first;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;

            //always hits the monster with the highest current health....the amount of HP it has just before the final, fatal blow.
            if(x%k==0) x =k;
            else x=x%k;
            arr[i] = {x,i+1};

        }

        sort(arr.begin(),arr.end(),comp);
        
        for(int i=0;i<n;i++) cout<<arr[i].second<<" ";
        cout<<endl;

        // priority_queue<pair<int,int>> maxh;

        // for(int i=0;i<n;i++) {
        //     int x;
        //     cin>>x; 

        //     // Optimization: Use modulo to skip simulation
        //     //always hits the monster with the highest current health....the amount of HP it has just before the final, fatal blow.
        //     if(x % k == 0) x = k;
        //     else x = x%k;


        //     // negative index as for pq if first is equal → second → larger wins....but If health is same → choose smaller index
        //     maxh.push({x,-(i+1)});
        // }


        // vector<int> ans;

        // while(!maxh.empty()){

        //     auto top = maxh.top();
        //     maxh.pop();

        //     int node = top.first;
        //     int idx = -top.second;

        //     node = node-k;
        //     if(node<=0) ans.push_back(idx);
        //     else maxh.push({node,-idx});
        // }
        
        // for(int i=0;i<n;i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
    }

}