#include<bits/stdc++.h>
using namespace std;

long long fun(vector<long long>& arr,int l,int r){  

    long long maxsum = arr[l],currsum = arr[l]; 

    for(int i=l+1;i<=r;i++){ 

        currsum = max(arr[i] , arr[i]+currsum);
        maxsum = max(maxsum,currsum); 

        if(currsum<=0){
            currsum=0; 
        }
        
    }

    return maxsum;

    //just use the function twice...from 1 to n-1 ...and then 2 to n
    /*Failing Test Case:......
    n = 4
    arr = [-5, 10, 10, 10] 
    The total sum is 25. The maximum proper subarray is [10, 10, 10] with a sum of 30.
    Because the original logic strictly limits the size to n-1 inside a single Kadane's pass, 
    it stops processing at index 2 once the size limit is hit. It calculates the max sum as 20 
    (from index 1 to 2) and completely ignores the last element. Since 25 > 20, it incorrectly 
    outputs YES instead of the expected NO.
    */
    // long long maxsum=arr[0],currsum = arr[0];
    // int size =1;

    // for(int i=1;i<n;i++){

    //     if(size<n-1){
    //         currsum = max(arr[i] , arr[i]+currsum);
    //         maxsum = max(maxsum,currsum);
    //         size++;

    //         if(currsum<=0){
    //             currsum=0;
    //             size=0;
    //         }
    //     }
    // }

    //return maxsum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);

        long long sum=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            sum+=arr[i];
        }

        //long long maxsubarraysum = max(fun(arr,n));
        long long maxsubarraysum = max(fun(arr,0,n-2) , fun(arr,1,n-1));
        if(sum > maxsubarraysum) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }

}