#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr.rbegin(),arr.rend());

        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+1);
        reverse(arr.begin()+1,arr.end());

        int sum=0;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(arr[i]==sum){
                flag = false;
                break;
            }
            else sum+=arr[i];
        }

        if(flag){
            cout<<"YES"<<endl;
            for(int x:arr) cout<<x<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }

}