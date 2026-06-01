#include<bits/stdc++.h>
using namespace std;


long long lb1(long long x,long long k){

    long long low = 1 , high =  k, ans = -1;

    while(low<=high){
        long long mid = low + (high-low)/2;

        if(mid*(mid+1)/2 >= x){
            ans = mid;
            high = mid-1;
        }

        else low = mid+1;
    }

    return ans;
}

long long lb2(long long x,long long k){

    long long low = 1 , high =  k-1, ans = 1;

    while(low<=high){
        long long mid = low + (high-low)/2;

        if(mid*(2*k - mid -1)/2 >= x){
            ans = mid;
            high = mid-1;
        }

        else low = mid+1;
    }

    return ans;
}

long long fun(long long k,long long x){

    if(k==1) return 1;
    long long sum = k*(k+1)/2;  

    if(x<=sum){
        return lb1(x,k);
    }

    else{
        long long left = x - sum;
        long long sum2 = k*(k-1)/2;

        if(left>=sum2) return 2*k-1;
        return k + lb2(left,k);
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long k,x;
        cin>>k>>x;
        cout<<fun(k,x)<<endl;
    }

}