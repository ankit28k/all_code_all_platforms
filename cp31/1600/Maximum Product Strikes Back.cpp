#include<bits/stdc++.h>
using namespace std;

int prod(vector<int>& arr,int l,int r){

    if(l<0 || r<0) return 0;
    if(l==r) return arr[l];

    int n = r-l+1;
    vector<int> psum(n),ssum(n);

    psum[0] = arr[l] ;
    ssum[n-1] = arr[r];

    for(int i=1;i<n;i++) psum[i] = psum[i-1]*arr[l+i];
    for(int i=n-2;i>=0;i--) ssum[i] = ssum[i+1]*arr[l+i];

    int ans =0;
    for(int i=0;i<n;i++){
        if(arr[i+l]<0){
            int left =0,right =0;
            if(i>0) left = psum[i-1];
            if(i<n-1) right = ssum[i+1];

            ans = max({ans,left,right});
        }
    }

    return ans;

}

int maxp(vector<int>& nums) {
    int n = nums.size(), ans =0 ;

    if(n==1) return nums[0];
    
    int prev=0 , ncnt =0 , csum=0;

    for(int i=0;i<n;i++){
        
        if(nums[i]==0){

            if(ncnt%2 !=0) ans = max(ans,prod(nums,prev,i-1));
            else ans = max(ans,csum);

            ncnt =0;
            prev = i+1;
            csum =0;
        }
        else {
            if(csum ==0) csum = nums[i];
            else csum *= nums[i];
        }
        
        if(nums[i]<0) ncnt++;
        
        
    }
    
    if(nums[n-1] != 0){
        if(ncnt%2 !=0) ans = max(ans,prod(nums,prev,n-1));
        else if(ncnt%2 ==0) ans = max(ans,csum);
    }
    
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int maxprod = maxp(arr);
        
    }

}