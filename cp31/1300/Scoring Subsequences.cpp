#include<bits/stdc++.h>
using namespace std;

// int fun(vector<long long>& arr,long long val,int r){
//     int l=0,h=r;
//     int ans=r;
//     while(l<=h){
//         int mid = l+(h-l)/2;
//         // long long cp;
//         // if(mid>0) cp = arr[r]/arr[mid-1];
//         // else cp = arr[r];
 
//         // if(cp/(r-mid+1) >= val){
//         //     ans = mid;
//         //     h=mid-1;
//         // }
//         // else l = mid+1;

//         if(mid>0) {
//             if(arr[r]>=val*(r-mid+1)*arr[mid-1]){
//                 ans = mid;
//                 h=mid-1;
//             }
//             else l = mid+1;
//         }

//         else{
//             if(arr[r]>=val*(r-mid+1)){
//                 ans = mid;
//                 h=mid-1;
//             }
//             else l = mid+1;
//         }
//     }

//     return ans;
// }

int fun(vector<long long>& arr,int r){
    int l=0,h=r;
    int ans=r;
    while(l<=h){
        int mid = l+(h-l)/2;
 
        if(arr[mid] >= r-mid+1){
            ans = mid;
            h=mid-1;
        }
        else l=mid+1;
    }

    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        // vector<long long> pp(n);
        // pp[0] = arr[0];
        // for(int i=1;i<n;i++){
        //     pp[i] = pp[i-1]*arr[i];
        // }


        
        vector<int> ans(n);


        //M1 TC-> O(nlogn)
        // for(int i=0;i<n;i++){
        //     // int r = i , l = fun(pp,arr[i],i); // as its factorial d! not d...so no need of product prefix
        //     int r = i , l = fun(arr,i);
        //     ans[i] = r-l+1;
        // }

        //M2 TC-> O(n)
        int l=0,r=0;
        while(r<n){

            while(l<=r && arr[l]<(r-l+1)) l++;
            
            ans[r] = r-l+1;
            r++;
        }

        for(int x:ans) cout<<x<<" ";
        cout<<endl;

    }

}