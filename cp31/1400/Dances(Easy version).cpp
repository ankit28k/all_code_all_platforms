#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> crr(n) ,arr(n);
        crr[0]=1;
        for(int i=1;i<n;i++) cin>>crr[i];
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(crr.begin(),crr.end());
        sort(arr.begin(),arr.end());

        vector<int> maxel(n,0);

        for(int i=0;i<n;i++){

            int idx = upper_bound(arr.begin(),arr.end(),crr[i]) - arr.begin(); 
            int greater_el = n-idx;
            maxel[i] = greater_el;
        }

        int cnt=0;
        for(int i=n-1;i>=0;i--){
            
            if(maxel[i]==0) continue;
            if(maxel[i]-cnt > 0) cnt++;
            // else break;
        }
        cout<<n-cnt<<endl;
    }

}