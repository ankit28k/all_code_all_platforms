#include<bits/stdc++.h>
using namespace std;

bool fun(string& arr,int l,int r){
    int cnt=0;
    for(int i=l;i<=r;i++){
        if(arr[i]=='0') cnt++;
    }
    return cnt>0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        int cnt=0;
        for(int i=0;i<=n-k;i+=k){
            if(!fun(s,i,i+k-1)) cnt++;
        }

        cout<<cnt<<endl;
    }

}