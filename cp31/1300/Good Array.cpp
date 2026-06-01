#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr[i] = {x,i};
    }
    
    sort(arr.begin(),arr.end());
    long long sum = 0; 

    for(int i=0;i<n;i++) sum+=arr[i].first; 

    int maxi = arr[n-1].first;
    sum -= maxi;
    
    vector<int> ans;
    for(int i=0;i<n-1;i++){
        long long temp = sum - arr[i].first;
        if(temp==maxi) ans.push_back(arr[i].second+1);
    }

    sum -= arr[n-2].first;
    if(sum == arr[n-2].first) ans.push_back(arr[n-1].second + 1);


    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<" ";
    cout<<endl;

}