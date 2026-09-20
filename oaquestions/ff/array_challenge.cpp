#include<bits/stdc++.h> 
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int mxsum=-1,cmin = arr[0];
    for(int i=1;i<n;i++){
        int cp = arr[i]-cmin;
        mxsum = max(mxsum,cp);

        cmin = min(cmin,arr[i]);
    }
    cout<<mxsum<<endl;
}