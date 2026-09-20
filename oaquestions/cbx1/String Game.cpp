#include<bits/stdc++.h>
using namespace std;


bool poss(int m,string& s,string& p,int n,vector<int>& arr){

    vector<bool> vis(n,true);
    for(int i=0;i<=m;i++){
        vis[arr[i]-1] = false;
    }
    string t = "";
    for(int i=0;i<n;i++){
        if(vis[i]) t.push_back(s[i]);
    }

    int i=0,j=0 , nt = t.length() , np = p.length();
    while(i<nt && j<np){
        if(t[i]==p[j]) {
            i++;
            j++;
        }
        else if(t[i] != p[j]) i++;
    }

    return j>=np;
}
int main(){
    string s,t;
    cin>>s>>t;
    int n = s.length();
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int l=0,h=n-1,ans=0;
    while(l<=h){
        int m = l+(h-l)/2;
        if(poss(m,s,t,n,arr)){
            ans = m+1;
            l=m+1;
        }
        else h=m-1;
    }

    cout<<ans<<endl;

}