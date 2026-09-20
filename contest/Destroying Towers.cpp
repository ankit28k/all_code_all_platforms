#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n) , nsl(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) nsl[i] = -1;
            else nsl[i] = st.top();

            st.push(i);
        }

        for(int i=0;i<n;i++){
            if(nsl[i]==-1) continue;
            int idx = nsl[i];
            arr[i] = arr[idx];
        }

        long long sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        cout<<sum<<endl;
    }

}