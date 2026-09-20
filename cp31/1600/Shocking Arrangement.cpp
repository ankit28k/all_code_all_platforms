#include<bits/stdc++.h>
using namespace std;

bool fun(vector<int>& arr,int n){
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        multiset<int> arr;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            arr.insert(x);
        }

        int val = *prev(arr.end())- *(arr.begin());
        vector<int> temp;

        while(arr.size()>0){
            int maxi ;
            if(arr.size()>0) {
                maxi= *prev(arr.end());
                temp.push_back(maxi);
                arr.erase(prev(arr.end()));
            }
            int mini ;
            if(arr.size()>0) {
                mini = *(arr.begin());
                temp.push_back(mini);
                arr.erase(arr.begin());
            }
            
        }

        map<int,int> mp;
        int sum=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            sum+=temp[i];
            int tar = sum-val;

            auto it = mp.upper_bound(tar);
            if(it != mp.begin()) flag = false;

            mp[sum]++;
        }

        if(flag && n>1) {
            cout<<"YES"<<endl;
            for(int x:temp) cout<<x<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
        
    }

}