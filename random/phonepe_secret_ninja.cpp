#include <bits/stdc++.h>
using namespace std;

bool comp(long long val,const pair<long long,long long>& p){
    return p.first>val;
}
vector<long long> solve(int n, int k, int q, vector<long long>& trees, vector<long long>& time, vector<long long>& queries) {
    
    vector<pair<long long,long long>> arr(k);
    
    for(int i=0;i<k;i++) arr[i] ={trees[i],time[i]};
    
    sort(arr.begin(),arr.end());

    long long tottaltime=0;
    for(int i=0;i<k;i++){
        tottaltime += time[i];
        arr[i] ={trees[i],tottaltime};
    }

    vector<long long> ans(q);
    for(int i=0;i<q;i++){
        long long val = queries[i];
        int idx = upper_bound(arr.begin(),arr.end(),val,comp) - arr.begin();
        idx--;

        if(idx<0){
            // ans[i] = (val*arr[0].second) / arr[0].first;
            long long dist = arr[0].first;
            if(dist == 0) ans[i] = 0;
            else ans[i] = (val*arr[0].second) / dist;
        }
        else if(idx==k-1){
            long long left = val - arr[idx].first;
            if(left==0) {
                ans[i] = arr[idx].second;
            }
            else{
                long long dist = arr[idx].first , timetaken=arr[idx].second;
                if(idx>0) dist = arr[idx].first - arr[idx-1].first;
                if(idx>0) timetaken = arr[idx].second - arr[idx-1].second;

                //ans[i] = arr[idx].second + left*timetaken/dist;
                if(dist == 0) ans[i] = arr[idx].second;
                else ans[i] = arr[idx].second + left*timetaken/dist;
            }
        }
        else {
            long long left = val - arr[idx].first;
            long long dist = arr[idx+1].first - arr[idx].first;
            long long timetaken = arr[idx+1].second - arr[idx].second;
            
            //ans[i] = arr[idx].second + left*timetaken/dist;
            if(dist == 0) ans[i] = arr[idx].second;
            else ans[i] = arr[idx].second + left*timetaken/dist;
        }
    }

    return ans;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> trees(k);
    for (int i = 0; i < k; i++) cin >> trees[i];
    vector<long long> time(k);
    for (int i = 0; i < k; i++) cin >> time[i];
    vector<long long> queries(q);
    for (int i = 0; i < q; i++) cin >> queries[i];
    vector<long long> results = solve(n, k, q, trees, time, queries);
    for (long long r : results) cout << r << " ";
    cout<<endl;
    return 0;
}
