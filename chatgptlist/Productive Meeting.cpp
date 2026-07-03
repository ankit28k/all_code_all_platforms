#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        multiset<pair<int,int>> st;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]>0) st.insert({arr[i],i+1});
        }

        int cnt=0;
        vector<pair<int,int>> ans;
        while(st.size()>1){
            auto f = *(st.begin()) , l = *prev(st.end());
            st.erase(f);
            st.erase(l);

            int i = f.second , j = l.second;
            ans.push_back({i,j});
            int val1 = f.first , val2 = l.first;
            val1--;
            val2--;
            cnt++;

            if(val1>0) st.insert({val1,i});
            if(val2>0) st.insert({val2,j});

        }

        cout<<cnt<<endl;
        for(auto it:ans) cout<<it.first<<" "<<it.second<<endl;
    }

}