#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++) {
            arr[i] = s[i-1]-'0';
        }

        long long ans=0;
        vector<bool> vis(n+1,false);

        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                if(arr[j]==1) break;
                if(!vis[j]) {
                    ans += i;
                    vis[j] = true;
                }
            }
        }

        cout<<ans<<endl;
         
    }

}