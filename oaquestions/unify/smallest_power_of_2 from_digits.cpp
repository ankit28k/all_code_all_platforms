#include<bits/stdc++.h>
using namespace std;

// bool nobitone(int n){
//     int cnt=0;
//     while(n!=0){
//         n = n&(n-1);
//         cnt++;
//     }
//     return cnt==1;
// }

bool poss(vector<int>& fq,vector<int>& fqp2){
    for(int i=0;i<10;i++){
        if(fq[i]<fqp2[i]) return false;
    }
    return true;
}
int main(){
    string s;
    cin>>s;

    int n = s.length();

    //it fails for rearrange logic
    // vector<int> suma;

    // long long ans=-1,maxbits=n;
    // for(int mask=0;mask<(1<<n);mask++){
    //     long long sum=0;
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         if((mask>>i)&1){
    //             sum = sum*10 + s[i]-'0';
    //             cnt++;
    //         }
    //     }
    //     if(nobitone(sum)){
    //         if(cnt<maxbits){
    //             maxbits = cnt;
    //             ans = sum;
    //         }
    //         else if(cnt==maxbits){
    //             if(ans==-1) ans=sum;
    //             else ans = min(ans,sum);
    //         }
    //     }
    // }
    
    // cout<<ans<<endl;

    vector<long long> pow2(61);
    for(int i=0;i<61;i++){
        pow2[i]= 1LL<<i;
    }

    vector<int> fq(10,0);
    for(char c:s) fq[c-'0']++;

    long long ans=-1;
    for(int i=0;i<61;i++){
        vector<int> fqpw2(10,0);
        long long temp=pow2[i];

        while(temp){
            int ld = temp%10;
            fqpw2[ld]++;
            temp = temp/10;
        }

        if(poss(fq,fqpw2)){
            ans = pow2[i];
            break;
        }
        else ans=-1;
    }
    cout<<ans<<endl;

}