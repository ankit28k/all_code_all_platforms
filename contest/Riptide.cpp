#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> arr(3);
        for(int i=0;i<3;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int ans= min({arr[2]-arr[1],arr[1]-arr[0]});
        cout<<ans<<endl;
    }

}