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

        sort(arr.begin(),arr.end());
        int val = arr[n/2];
        int i=(n/2)-1 , j= (n/2) +1;

        while(j<n && arr[j]==val) j++;
        while(i>=0 && arr[i]==val) i--;

        int ans=0;
        while(i>=0 && j<n){
            ans++;
            i--;
            j++;

        }

        if(j>=n && i>=0) ans += i+1;
        else if(j<n && i<0) ans+= n-j;
        cout<<ans<<endl;
    }

}