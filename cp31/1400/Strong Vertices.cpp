#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n) , brr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];

        vector<int> crr(n);
        for(int i=0;i<n;i++) crr[i] = arr[i]-brr[i];
    }

}