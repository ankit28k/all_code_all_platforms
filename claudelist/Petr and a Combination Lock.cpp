#include<bits/stdc++.h>
using namespace std;

string fun(vector<int>& arr,int n,int sum){

    vector<int> dp(1<<n);
    for(int mask=0;mask<(1<<n);mask++){

        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                dp[mask] += arr[i];
            }
        }
    }

    for(int mask = 0;mask<(1<<n)-1;mask++){
        int psum = dp[mask] , nsum = sum-dp[mask];
        if(psum-nsum==0 || (psum-nsum)%360==0) return "YES";
    }
    if(dp[(1<<n)-1]==0 || dp[(1<<n)-1]%360==0) return "YES";
    return "NO";
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<fun(arr,n,sum)<<endl;
}