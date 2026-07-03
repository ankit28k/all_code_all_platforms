#include<bits/stdc++.h>
using namespace std;

bool poss(long long mid,vector<long long>& arr,long long n,long long m){
    long long ans=0;
    for(int i=0;i<n;i++){
        
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<long long> arr(m);
        for(int i=0;i<n;i++)  cin>>arr[i]; 

        long long l=1,h=1e18,ans=1e18;
        while(l<=h){
            long long mid = l+(h-l)/2;
            if(poss(mid,arr,n,m)){
                ans = m;
                h=mid-1;
            }
            else l = mid+1;
        }

    }

}