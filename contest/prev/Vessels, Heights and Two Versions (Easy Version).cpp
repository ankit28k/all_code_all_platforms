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

        for(int i=0;i<n;i++){
            vector<int> cw(n) ,ccw(n);
            int maxi =0;
            for(int j=1;j<n;j++){
                maxi = max(maxi,arr[(i+j-1)%n]);
                cw[(i+j)%n]=maxi;
            }
            maxi=0;
            for(int j=1;j<n;j++){
                maxi = max(maxi,arr[(i-j+n)%n]);
                ccw[(i-j+n)%n]=maxi;
            }
            long long ans=0;
            for(int j=0;j<n;j++){
                if(i!=j)ans+=min(cw[j],ccw[j]);
            }
            cout<<ans<<" ";
        }

        cout<<endl;
    }

}