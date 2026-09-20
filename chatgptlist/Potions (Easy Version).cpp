#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    long long sum=0;
    multiset<int> st;
    int cnt=0;

    for(int i=0;i<n;i++){
        sum += arr[i];
        if(arr[i]<0) st.insert(arr[i]);

        while(sum<0){
            auto it = st.begin();
            int val  = *it;
            sum-=val;
            st.erase(it);
            cnt++;
        }
    }

    cout<<n-cnt<<endl;



}