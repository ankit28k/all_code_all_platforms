#include<bits/stdc++.h>
using namespace std;

string fun(string& s,int n,int k){
    
    vector<int> cnt(k,0);

    for(int i=0;i<n;i++){
        if(s[i]=='1') cnt[i%k]++;
    }

    for(int i=0;i<k;i++){
        if(cnt[i]%2 != 0) return "NO";
    }

    return "YES";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        cout<<fun(s,n,k)<<endl;
        
    }

}