#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr,int n,int k){
     
    // at solving...ex a,b,c
    
    // last left is a  , bc removed=> (a-b) (c-b) => (a-b) - (c-b) => a-c
    // last left is a  , cb removed=> (a-c) (b-c) => (a-c) - (b-c) => a-b

    // same for b,c ....we get difference of 2 numbers.....=> find 2 numbers such that their difference is x

    set<int> st;
    for(int i=0;i<n;i++) st.insert(arr[i]);

    for(int x:st){
        if(st.find( x + k) != st.end()) return true;
    }

    return false;

    // pair<int,int> maxi = {INT_MIN,-1};
    // for(int i=0;i<n;i++){
    //     if(maxi.first < arr[i]){
    //         maxi.first = arr[i];
    //         maxi.second =i;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     if(i==maxi.second) continue;
    //     if(abs(arr[i]-maxi.first)==k) return true;
    // }

    // return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
 
        if(check(arr,n,k)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }

}