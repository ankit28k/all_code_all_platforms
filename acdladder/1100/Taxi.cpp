#include<bits/stdc++.h>
using namespace std;

int fun(int cnt1,int cnt2,int cnt3,int cnt4){

    int ans=0;
    ans += cnt4 + min(cnt1,cnt3) + cnt2/2 ;

    int n2 = cnt2%2;

    if(cnt1>cnt3)  {
        int n1 = cnt1 - cnt3;
        if(n2==1) {
            n1 -=2;
            ans++;
        }
        ans+= (n1+4-1)/4;
        return ans;
    }

    if(cnt1<cnt3) {
        int n3 = cnt3-cnt1;
        ans += n3 + n2;
        return ans;
    }

    if(cnt1==cnt3){
        ans+=n2;
        return ans;
    }

    return -1;
}
int main(){
    
    int n;
    cin>>n; 

    int cnt1=0,cnt2=0,cnt3=0,cnt4=0 ;

    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(x==1) cnt1++;
        if(x==2) cnt2++;
        if(x==3) cnt3++;
        if(x==4) cnt4++;
        
    } 

    cout<<fun(cnt1,cnt2,cnt3,cnt4)<<endl;
    

    

}