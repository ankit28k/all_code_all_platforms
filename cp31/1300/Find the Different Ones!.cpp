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

        int prev =-1;
        vector<int> diff;
        for(int i=0;i<n;i++){
            if(arr[i] != prev){
                prev = arr[i];
                diff.push_back(i+1);
            }
        }

        int q , dn = diff.size();
        cin>>q;
        vector<pair<int,int>> ans;
        while(q--){
            int l,r;
            cin>>l>>r;

            int idx = lower_bound(diff.begin(),diff.end(),l) - diff.begin();

            if(l==r) ans.push_back({-1,-1});

            else if(idx == dn) ans.push_back({-1,-1}); //if cant find
            else if(diff[idx] > l && diff[idx]<=r) ans.push_back({l,diff[idx]});
            else if(diff[idx] > l && diff[idx] > r) ans.push_back({-1,-1});

            else if(diff[idx]==l){

                if(idx==dn-1) ans.push_back({-1,-1});
                else{
                    if(diff[idx+1]>r) ans.push_back({-1,-1});
                    else ans.push_back({l,diff[idx+1]});
                }

                
            }
        }
        for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;
        cout<<endl;
        
    }

}