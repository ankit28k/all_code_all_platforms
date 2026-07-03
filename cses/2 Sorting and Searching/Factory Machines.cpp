#include<bits/stdc++.h>
using namespace std;
bool poss(long long m,vector<int>& arr,int t,int n){
    long long cnt=0;
    for(int i=0;i<n;i++){
        cnt += m/arr[i];

        if(cnt>=t) return true;
    }

    return cnt>=t;
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    long long l=1,h=1e18,ans=1e18; //5*10^12 precise
    while(l<=h){
        long long m = l+(h-l)/2;
        if(poss(m,arr,t,n)){
            ans = m;
            h=m-1;
        }
        else l=m+1;
    }

    cout<<ans<<endl;

}