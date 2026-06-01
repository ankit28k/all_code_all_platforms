#include<bits/stdc++.h>
using namespace std;

vector<long long> fun(vector<long long>& arr,vector<long long>& brr,int n){

    map<long long,vector<long long>> mp;

    long long maxi = LLONG_MIN;

    for(int i=0;i<n;i++) {
        long long temp = arr[i]-brr[i];
        mp[temp].push_back(i+1);
        maxi = max(maxi,temp);
    }

    return mp[maxi];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n),brr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];

        vector<long long> ans = fun(arr,brr,n);

        sort(ans.begin(),ans.end());
        
        cout<<ans.size()<<endl;
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;


    }

}