#include<bits/stdc++.h>
using namespace std;


long long fun2(string& s,int n,int st){

    long long ans=0 , ini = st;
    for(int i=0;i<n;i++){
        if(s[i]=='*'){
            ans += abs(st - i);
            st++;
        }
    }

    return ans;

}
long long fun(string& s,int n,int median,int cnt){
    int left = cnt-1;
    return min(fun2(s,n,median - (left/2)) , fun2(s,n,median - (left/2) + 1)); 
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<int> pos;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*') {
                pos.push_back(i);
                cnt++;
            }
            
        }
        
        int pn = pos.size();

        sort(pos.begin(),pos.end());  
        long long ans ;
        if(pn>2) {

            if(pn%2 ==0) ans = min(fun(s,n,pos[pn/2],cnt),fun(s,n,pos[(pn/2)-1],cnt)) ;
            else ans = fun(s,n,pos[pn/2],cnt);
        }

        else if(pn==2) ans=min(fun(s,n,pos[0],cnt),fun(s,n,pos[1],cnt)) ;
        else ans =0;

        cout<<ans<<endl;
        
    }

}