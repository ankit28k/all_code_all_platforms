#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y,k;
        cin>>x>>y>>k;
        
        int val = y-x;
        long long ans=0 , i=0;

        for(;i<k;i++){
            if((y+i)%(x+i) != val) ans += (y+i)%(x+i);
            else break;
        }
        if(k>i) ans += 1LL*val*(k-1-(i)+1);
        cout<<ans<<endl;
    }

}