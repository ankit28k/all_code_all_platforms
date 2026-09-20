#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
int main(){
    long long n,r,avg;
    cin>>n>>r>>avg;
    vector<pair<int,int>> arr(n);
    long long sum=0;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        sum+=a;
        arr[i] = {b,a};
    }
    long long req = 1LL*avg*n - sum;
    sort(arr.begin(),arr.end(),comp);

    int i=0;
    long long ans=0;
    while(req>0){
        int maxg = min(r - arr[i].second,req) ;
        int cost = arr[i].first;
        ans += 1LL*cost*maxg;
        req -= maxg;
        i++;
    }
    
    cout<<ans<<endl;

}




// long long fun(int idx,long long left,int n,int maxp,vector<int>& arr,vector<int>& brr){
//     if(left==0) return 0;
//     if(idx==n-1){
//         if(left<=maxp-arr[idx]) return left*brr[idx];
//         return 1e9;
//     }

//     int curr =arr[idx];
//     long long ans=1e18;
//     for(int fq=0;fq<=min((long long)maxp-curr,left);fq++){ // not maxp-curr,left-curr
//         long long temp = fq*brr[idx] + fun(idx+1,left-fq,n,maxp,arr,brr);
//         ans = min(ans,temp);
//     }
//     return ans;
// }
// int main(){
//     long long n,r,avg;
//     cin>>n>>r>>avg;
//     vector<int> arr(n),brr(n);
//     for(int i=0;i<n;i++) cin>>arr[i]>>brr[i];

//     long long sum=0;
//     for(int x:arr) sum+=x;
//     long long req = avg*n - sum;

//     int maxp;
//     cin>>maxp;
//     long long ans = fun(0,req,n,maxp,arr,brr);


// }