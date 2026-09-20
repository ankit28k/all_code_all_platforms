#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr(m+2,0);
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            arr[x]++;
        }
        
        vector<int> sf(m+2,0);
        for(int i=m;i>=1;i--){
            sf[i] = sf[i+1] + arr[i];
        }
        long long ans = 0;
        for(int i=1;i<=m;i++){
            if(i>=20){
                cout<<ans<<endl;
                continue;
            }

            long long pw = 1LL<<i;
            long long temp=0;

            for(int j=1;j<=m;j++){
                long long curr = 0;
                for(long long k = 1;k<pw && j*k<=m;k++) curr += sf[k*j];
                if(pw*j<=m) curr +=arr[pw*j];
                temp = max(temp,curr);
            }
            ans = temp;
            cout<<ans<<" ";
            
        }
        cout<<endl;
        
    }
    

}