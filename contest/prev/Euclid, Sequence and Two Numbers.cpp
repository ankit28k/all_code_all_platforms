#include<bits/stdc++.h>
using namespace std;

pair<int,int> fun(vector<int>& arr,int n){
    sort(arr.rbegin(),arr.rend());
    
    for(int i=2;i<n;i++){
        if(arr[i-2]%arr[i-1] != arr[i]) return {-1,-1};
    }

    return {arr[0],arr[1]};
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        pair<int,int> ans = fun(arr,n);

        if(ans.first==-1) cout<<-1<<endl;
        else cout<<ans.first<<" "<<ans.second<<endl;
    }

}