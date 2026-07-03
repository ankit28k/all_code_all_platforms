#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    vector<int> minr(n);
    minr[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--) minr[i] = min(minr[i+1],arr[i]);
    vector<int> ans(n,-1);

    for(int i=0;i<n;i++){
        int idx = lower_bound(minr.begin()+i+1,minr.end(),arr[i]) - minr.begin();
        idx--;
        if(i<idx) ans[i] = idx-i-1;
    }

    
    for(int x:ans) cout<<x<<" ";
    cout<<endl;

}