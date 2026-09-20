#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++) {
        long long l,r;
        cin>>l>>r;
        int cnt=0;
        long long ans=l;

        for(int bit=0;bit<61;bit++){
            if((l>>bit)&1)  cnt++;
            else{
                l |= (1LL<<bit);
                if(l>r) break;
                else cnt++;
            }

        }

        for(int bit=0;bit<61;bit++){
            if(((ans>>bit)&1) ==0  && cnt>0) {
                ans |= (1LL<<bit);  
            }
            cnt--;
            if(cnt<=0) break;

        }


        cout<<ans<<endl;

    }

}