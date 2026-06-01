#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,x;
        cin>>n>>s>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int sum = accumulate(arr.begin(),arr.end(),0);
        int diff = s-sum;

        if(diff>=0 && diff%x==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

}