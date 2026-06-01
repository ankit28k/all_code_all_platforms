#include<bits/stdc++.h>
using namespace std; 

string fun(vector<int>& arr,int n){

    vector<int> temp;

    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        int idx = lower_bound(arr.begin(),arr.end(),i+1) - arr.begin();
        int great_equal_el = n-idx;
        temp.push_back(great_equal_el);
    }

    reverse(arr.begin(),arr.end());
    
    for(int i=0;i<n;i++){
        if(arr[i] != temp[i]) return "NO";
    }

    return "YES";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        cout<<fun(arr,n)<<endl;
        

    }

}