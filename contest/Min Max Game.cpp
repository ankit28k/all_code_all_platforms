#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        int zcnt=0 , ocnt=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]==1) ocnt++;
            else zcnt++;
        }

        if(zcnt>ocnt) cout<<"Elsie"<<endl;
        else cout<<"Bessie"<<endl;
    }

}