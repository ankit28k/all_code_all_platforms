#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,x;
        cin>>a>>b>>x;

        long long ans =LLONG_MAX;
        long long diff = abs(a-b);

        ans = min(ans,diff);

        long long cnt=0;

        while(a != b){
            if(a==b) break;
            if(a>b) {
                a = a/x;
                cnt++;
                ans = min(ans,cnt+abs(a-b));
            }
            else if(b>a) {
                b = b/x;
                cnt++;
                ans = min(ans,cnt+abs(a-b));
            }
        }

        cout<<ans<<endl;
    }

}