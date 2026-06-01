#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,h,l;
        cin>>n>>h>>l;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr.begin(),arr.end());

        int mn = min(h,l) , mx = max(h,l);
        
        int j=n-1;
        while(j>=0 && arr[j]>mx){
            j--;
        }

        int ans =0;
        for(int i=0;i<j;i++,j--){
            if(arr[i]<=mn) ans++;
        }

        cout<<ans<<endl;
    }

}