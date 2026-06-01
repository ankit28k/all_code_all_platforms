#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
 
        vector<int> ans(n); 
        ans[n-1] = 1;
        ans[n-2] = n;

        for(int i=n-3;i>=0;i-=2){
            ans[i] = ans[i+2] +1;
        }

        for(int i=n-4;i>=0;i-=2){
            ans[i] = ans[i+2]-1;
        }

        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;

    }

}