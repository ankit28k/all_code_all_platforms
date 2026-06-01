#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        //using sliding window

        int l=0,r=0,w_cnt=0 , ans =INT_MAX;

        while(r<n){

            if(s[r]=='W') w_cnt++;

            if(r-l+1 <k) r++;
            
            else if(r-l+1==k){

                ans = min(ans,w_cnt);
                
                if(s[l]=='W') w_cnt--;

                l++;
                r++;

            }

        }

        cout<<ans<<endl;
        





        // int temp=0,ans=0,cnt=0;
        // for(int i=0;i<s.length()-1;i++){
        //     if(s[i]=='B') {
        //         temp++;
        //         cnt++;
        //     }
        //     else{
        //         ans = max(ans,temp);
        //         temp=0;
        //     }

        // }

        // ans = max(ans,temp);
        // int left = n-cnt;
        // cout<<max(0,min(k-ans,left))<<endl;
        
    }

}