#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        if(m==1){
            long long maxi=LLONG_MIN;
            for(int i=0;i<n;i++) maxi = max(maxi,arr[i]);
            cout<<maxi<<endl;
            continue;
        }

        multiset<long long> st;
        long long sum=0;
        for(int i=0;i<m-1;i++){
            sum+=arr[i];
            st.insert(arr[i]);
        }

        long long ans=LLONG_MIN;
        for(int i=m-1;i<n;i++){
            long long curr = m*arr[i] -sum;
            ans = max(ans,curr);

            if(arr[i]< *(prev(st.end()))){
                sum -= *(prev(st.end()));
                st.erase(prev(st.end()));
                st.insert(arr[i]);
                sum+= arr[i];

            }
        }

        cout<<ans<<endl;
        
    }

}