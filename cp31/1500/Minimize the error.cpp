#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k1,k2;
    cin>>n>>k1>>k2;
    vector<int> arr(n),brr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>brr[i];

    multiset<pair<int,pair<int,int>>> st;

    for(int i=0;i<n;i++){
        st.insert({abs(arr[i]-brr[i]) , {arr[i],brr[i]}});
    }

    while(k1+k2>0){
        auto it = prev(st.end());
        auto l = *it;
        st.erase(it);

        int a= l.second.first ,b = l.second.second;
        if(k1>0) {
            if(a>b) a--;
            else a++;
            k1--;
            st.insert({abs(a-b),{a,b}});
        }

        else if(k2>0){
            if(b>a) b--;
            else b++;
            k2--;
            st.insert({abs(a-b),{a,b}});
        }
    }

    long long ans=0;
    for(auto it:st){
        ans += 1LL*it.first*it.first;
    }

    cout<<ans<<endl;

}