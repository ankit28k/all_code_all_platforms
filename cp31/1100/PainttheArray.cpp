#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

long long fun(vector<long long>& arr,int n){

    long long hcfo=0,hcfe=0;
    for(int i=0;i<n;i++){ 

        if(i%2==0) hcfo = gcd(hcfo,arr[i]);
        else hcfe = gcd(hcfe,arr[i]);
    }


    //checking on opposite index.......and returning as any value is accepted...
    bool ans =true;
    for(int i=0;i<n;i+=2){   
        if(arr[i]%hcfe ==0) ans =false;
    }

    if(ans) return hcfe;
    ans=true;

    for(int i=1;i<n;i+=2){
        if(arr[i]%hcfo ==0) ans =false;
    }

    if(ans) return hcfo;

    //fail case
    return 0;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        cout<<fun(arr,n)<<endl;
        
    }

}