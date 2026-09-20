#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> at(n),load(n);
    for(int i=0;i<n;i++) cin>>at[i];
    for(int i=0;i<n;i++) cin>>load[i];

    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) arr[i] = {at[i],load[i]};

    sort(arr.begin(),arr.end());
    vector<int> work(k,0);

    set<pair<int,int>> st;
    for(int i=0;i<k;i++) st.insert({0,i});

    for(int i=0;i<n;i++){
        int currt = arr[i].first , currload = arr[i].second;
        auto it = *(st.begin());

        int prevtime = it.first;
        int idx = it.second;

        if(currt>prevtime){
            work[idx] += currload;
            st.erase(it);
            st.insert({currload + prevtime,idx});
        }
        
    }

    int maxi=0;
    for(int i=0;i<n;i++) maxi = max(maxi,work[i]);

    vector<int> ans;
    for(int i=0;i<n;i++) {
        if(work[i]==maxi) ans.push_back(i+1);
    }

    for(int x:ans) cout<<x<<" ";
}