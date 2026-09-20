#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n) ,brr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i]>>brr[i];
        }

        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());

        long long ans;
        if(n%2==0){
            int x1 = arr[n/2] , x2 = arr[(n/2) -1];
            int y1 = brr[n/2] , y2 = brr[(n/2)-1];

            long long x = x1-x2 + 1;
            long long y = y1-y2 + 1;
            ans = x*y;            
        }
        else ans =1;

        cout<<ans<<endl;
    }

}