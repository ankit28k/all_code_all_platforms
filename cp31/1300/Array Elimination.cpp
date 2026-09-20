#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<int> cntbit(31,0);
        for(int i=0;i<n;i++){
            for(int bit=0;bit<31;bit++){
                if((arr[i]>>bit)&1) cntbit[bit]++;
            }
        }
        vector<bool> ans(n+1,true);
        for(int bit=0;bit<31;bit++){
            for(int i=1;i<=n;i++){
                if(cntbit[bit]%i != 0) ans[i]=false;
            }      
        }
        

        for(int i=1;i<=n;i++){
            if(ans[i]) cout<<i<<" ";
        }
        cout<<endl;
    }

}