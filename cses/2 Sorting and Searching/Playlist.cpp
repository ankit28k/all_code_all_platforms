#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans=1,l=0,r=0;
    set<int> st;

    while(r<n){

        
        while(st.find(arr[r]) != st.end()) {
            st.erase(arr[l]);
            l++;
        }
        st.insert(arr[r]);
        ans = max(r-l+1,ans);

        r++;
    }

    cout<<ans<<endl;

}