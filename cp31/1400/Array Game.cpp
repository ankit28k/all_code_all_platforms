#include<bits/stdc++.h>
using namespace std;

long long fun(vector<long long>& arr,long long n , long long k){

    if(k>2) return 0;

    long long ans = *min_element(arr.begin(),arr.end());
    set<long long> s(arr.begin(),arr.end());

    long long mk0 = -1;

    //k==1
    long long mindiff = LLONG_MAX;
    for(int i=0;i<n;i++){
        for(int j =i+1;j<n;j++){

            if(s.find(abs(arr[i]-arr[j])) != s.end()) mk0 = abs(arr[i]-arr[j]);
            mindiff = min(mindiff,abs(arr[i]-arr[j]));
        }
    }

    ans = min(ans,mindiff);
    if(k==1) return ans;
    
    //k == 2
    if(mk0 != -1) return 0;  //if can make min 0

    sort(arr.begin(),arr.end()); 

    for(int i=0;i<n;i++){
        for(int j =i+1;j<n;j++){
            long long diff = abs(arr[i]-arr[j]);
            long long lbidx = lower_bound(arr.begin(),arr.end(),diff) - arr.begin();
            ans = min(ans,abs(diff - arr[lbidx]));
            if(lbidx>0) ans = min(ans,abs(diff - arr[lbidx-1]));
        }
    }

    return ans;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i]; 

        cout<<fun(arr,n,k)<<endl;
    }

}