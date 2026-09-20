#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        int zcnt=0,ocnt=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]==0) zcnt++;
            else ocnt++;
        }

        if(zcnt<2){
            cout<<-1<<endl;
            continue;
        }
        if(arr[n-1]==0 && arr[0]==0) cout<<0<<endl;
        else if(arr[n-1]==0 || arr[0]==0) cout<<1<<endl;
        else cout<<2<<endl;
    }

}