#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        set<long long> st;
        map<long long,long long> mp;
        long long s=0;
        for(int i=0;i<n;i++) {
            long long x;
            cin>>x;
            s+=x;
            mp[x]++;
            st.insert(x);
        }
        
        vector<long long> arr;
        for(auto x:st) arr.push_back(x);

        //sort(arr.begin(),arr.end());  ...no need as set automatically sorts its contents

        long long ans=0;

        int i=0,j=arr.size()-1;
        
        while(i<=j){
            if(n*(arr[i]+arr[j]) == 2*s){

                if(i==j) {
                    long long v = mp[arr[i]];
                    ans += v*(v-1)/2;
                }
                else ans += mp[arr[i]]*mp[arr[j]];
                i++;
                j--;
            }
            else if(n*(arr[i]+arr[j]) > 2*s) j--;
            else i++;
        }

        cout<<ans<<endl;
    }

}