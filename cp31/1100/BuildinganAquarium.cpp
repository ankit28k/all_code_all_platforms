#include<bits/stdc++.h>
using namespace std;



bool ispossible(vector<int>& arr,long long h,int x){
    
    long long sum = 0;

    for(int i=0;i<arr.size();i++){
        if(arr[i] < h) {
            sum += h-arr[i];
            if(sum>x) return false;
        }
    }

    return sum<=x;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector<int> arr(n);

        
        for(int i=0;i<n;i++) cin>>arr[i];

        long long l=0, h= 1e9 + x; //In worst case a 1-length array), and a[0] = 10^9 and x water, the final height will be 10^9 + x.
        long long ans = -1; 
        while(l<=h){
            int mid = l + (h-l)/2;
            if(ispossible(arr,mid,x)){
                ans = mid;
                l = mid+1; 
            }

            else h = mid-1;
        }

        cout<<ans<<endl;
    }

}