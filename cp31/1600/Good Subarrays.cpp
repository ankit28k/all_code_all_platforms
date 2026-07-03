#include<bits/stdc++.h>
using namespace std;

long long subarrs_with_sum_k(vector<int>& arr, int n, long long k) {
    map<long long, long long> mp;
    mp[0] = 1;
    
    long long sum = 0, ans = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        long long target = sum - k;
        ans += mp[target];
        
        mp[sum]++;
    }
    
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            char ch;
            cin>>ch;
            arr[i] = ch-'0'-1;
        }

        cout<<subarrs_with_sum_k(arr,n,0)<<endl;
    }

}