#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            arr[i] ={a,b};
        }

        sort(arr.begin(),arr.end());
        
    }

}