#include<bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> arr,int n){
    
    bool oddp =false , evenp = false;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0) evenp = true;
        else oddp = true;
    }
    
    if(oddp && evenp){
        sort(arr.begin(),arr.end());
        return arr;
    }
    else return arr;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> ans = fun(arr,n);
        for(int x:ans) cout<<x<<" ";
        cout<<endl;
    }

}