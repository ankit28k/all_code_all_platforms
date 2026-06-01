
#include<bits/stdc++.h>
using namespace std;

int maxsubsum(vector<int>& arr ,int l,int r){
    
    if(l==r) return arr[l];

    int sum=arr[l],ans = arr[l];

    for(int i=l+1;i<=r;i++){
        sum = max(arr[i],sum+arr[i]);
        ans = max(ans,sum);

        if(sum<=0) sum=0;
    }

    return ans;
}

int fun(vector<int>& arr,int n){

    if(n==1) return arr[0];

    int prev=0;
    int ans = *max_element(arr.begin(), arr.end());
    //int ans= *max(arr.begin() ,arr.end()); ...gives error

    for(int i=1;i<n;i++){

        // if(abs(arr[i]%2) != abs(arr[i-1]%2)){
        //     temp++;
        // }

        if(abs(arr[i]%2) == abs(arr[i-1]%2)){
            ans = max(ans,maxsubsum(arr,prev,i-1));
            prev =i;
            //temp=1;
        }
    }

    ans = max(ans,maxsubsum(arr,prev,n-1));
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

        cout<<fun(arr,n)<<endl;
    }

}