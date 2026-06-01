#include<bits/stdc++.h>
using namespace std;

// k1 -> <= a+b , k2 -> >= a-b
//=> req (k1 & k2) = <=a+b - < a-b
bool check(vector<int>& arr,vector<int>& brr,int mid,int n,int m){

    for(int i=0;i<n;i++){
        int lessthanequal = upper_bound(brr.begin(),brr.end(),arr[i]+mid) - brr.begin();
        int lessthan = lower_bound(brr.begin(),brr.end(),arr[i]-mid) - brr.begin();

        if(lessthanequal - lessthan < 1) return false;
    }

    return true;
}
int main(){ 

    int n,m;
    cin>>n>>m;
    vector<int> arr(n) , brr(m);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++) cin>>brr[i];

    
    int l = 0,h = max(abs(arr[n-1] - brr[0]) , abs(arr[0]-brr[m-1]));
    int ans=h;
    while(l<=h){
        int mid = l + (h-l)/2;
        if(check(arr,brr,mid,n,m)){
            ans = mid ;
            h = mid-1;
        }

        else l = mid+1;
    }

    cout<<ans<<endl;
    

}