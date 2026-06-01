#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    long long x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<int> arr(n);
    arr[0]=x;
    for(int i=1;i<n;i++) arr[i] = (a*1LL*arr[i-1] + b)%c;
    
    vector<int> bits(31,0);

    long long ans =0;
    int r=0,l=0;

    for(;r<k;r++) {
        for(int i=0;i<31;i++){
            if((arr[r]>>i)&1) bits[i]++;
        }
    }

    for(int i=0;i<31;i++){
       if(bits[i]>0) ans += (1LL<<i);//pow(2,i);
    }
    
    while(r<n){
        
        long long temp=0;
        for(int i=0;i<31;i++){
            if((arr[r]>>i)&1) bits[i]++;
            if((arr[l]>>i)&1) bits[i]--;
            if(bits[i]>0) temp += (1LL<<i);//pow(2,i);
        }

        r++;
        l++;
        
        ans ^= temp;
    }
    cout<<ans<<endl;
}