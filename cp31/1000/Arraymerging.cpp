#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n),brr(n);

        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];

        unordered_set<int> s1,s2;

        unordered_map<int,int> m1 , m2;

        for(int i=0;i<n;i++){
            s1.insert(arr[i]);
            s2.insert(brr[i]);
        }

        for(auto x: s1) m1[x]++;
        for(auto x: s2) m2[x]++;
        

        int temp=1;
        for(int i=0;i<n-1;i++){

            if(arr[i]==arr[i+1]) temp++;
            else{
                m1[arr[i]] = max(m1[arr[i]],temp);
                temp=1;
            }
        }

        m1[arr[n-1]] = max(temp,m1[arr[n-1]]);

        temp =1;
        for(int i=0;i<n-1;i++){

            if(brr[i]==brr[i+1]) temp++;
            else{
                m2[brr[i]] = max(m2[brr[i]],temp);
                temp=1;
            }
        }

        m2[brr[n-1]] = max(temp,m2[brr[n-1]]);

        int ans=1;
        for(auto x:s1){
            if(s2.find(x) != s2.end()) ans = max(ans,m1[x]+m2[x]);
            else ans = max(ans,m1[x]);
        }

        for(auto x:s2){
            if(s2.find(x) != s1.end()) ans = max(ans,m1[x]+m2[x]);
            else ans = max(ans,m2[x]);
        }

        cout<<ans<<endl;

    }

}