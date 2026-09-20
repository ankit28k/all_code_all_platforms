#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<pair<int,pair<int,pair<int,int>>>> st;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int> temp(arr.begin()+i,arr.begin()+j+1);
                sort(temp.begin(),temp.end());

                bool dup = false;
                for(int k=1; k<temp.size(); k++){
                    if(temp[k] == temp[k-1]) dup = true;
                }

                int l = j-i+1;
                if(!dup && temp.back() - temp[0] == l - 1){
                    st.push_back({l, {temp[0], {i, j}}});
                }
                //st.insert({temp[0] , {temp[j-i],j-i+1}});
            }
        }

        int ans =0;
        for(auto it:st){
            for(auto it2 :st){
                int l1 = it.first, min1 = it.second.first, s1 = it.second.second.first, e1 = it.second.second.second;
                int l2 = it2.first, min2 = it2.second.first, s2 = it2.second.second.first, e2 = it2.second.second.second;
                
                if(l1 == l2 && (e1 < s2 || e2 < s1)){
                    if(min2 == min1 + l1){
                        ans = max(ans, l1);
                    }
                }
            }
            // int st = it.first , end = it.second.first , l = it.second.second;
            // auto it2 = st.lower_bound(end);
            // int l2 = it2.second.second;
            // if(l2>=l) ans = max(ans,l);
        }

        cout<<ans<<endl;
    }

}