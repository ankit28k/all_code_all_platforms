#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        bool flag = false;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]==67) flag =true;
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}