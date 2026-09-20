#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        
        vector<long long> ans(n);

        long long sum=0 , mini = arr[0];
        for(int i=0;i<n;i++){
            sum+= arr[i];
            ans[i] = min(mini,sum/(i+1));
            mini = min(mini,ans[i]);
        }

        for(int x:ans) cout<<x<<" ";
        cout<<endl;
    }

}