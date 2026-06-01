#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>& a , pair<int,int>& b){ 
    return a.first > b.first;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int k = (n*(n-1))/2;

        vector<int> arr(k);
        map<int,int> m;
        for(int i=0;i<k;i++) {
            cin>>arr[i];
            m[arr[i]]++;
        }

        vector<pair<int,int>> temp;
        for(auto it = m.begin();it !=m.end();it++){ 
            temp.push_back({it->first,it->second});
        }

        sort(temp.begin(),temp.end(),comp);

        vector<int> ans(n);
        int i=0,j=0;
        while(i<temp.size() && j<n){
            int val = temp[i].first;
            ans[j] = val;
            temp[i].second -= j;
            if(temp[i].second<=0) i++;
            j++;
        }

        reverse(ans.begin(),ans.end());
        for(int x:ans) cout<<x<<" ";
        cout<<endl;

        
    }

}