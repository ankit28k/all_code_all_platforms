#include<bits/stdc++.h>
using namespace std;

bool isprime(long long n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
long long fun(long long val){  
    
    if(val==1) return 2;
    if(val==2) return 3;

    int i;
    for(i=2;i<=val;i++){
        if(val%i != 0){
            if(isprime(i)) return i; 
        }
    }
    return -1;
}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        long long ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            ans = min(ans,fun(arr[i]));
        }
        cout<<ans<<endl;
    }

}