#include<bits/stdc++.h>
using namespace std;

//First find the highest factor of 2 that is number of trailing 0s for every number. 
//If the number of trailing zeros are X that implies it is not divisible by pow(2,k) where k is x+1,x+2....
//it is only divisible by pow(2,k) where k is x- 1,x -2.....0
//but if we perform operation, for a value of x....... 
//It adds 1 Add the place of x-1....make it not divisible by pow(2,k)....where k = x,x+1,x+2
//Example .....1110000, which is divisible by 2^4 and if 4 comes as x.....and operation is performed...it becomes
//  1111000....now this becomes divisible by pow(2,k).....where k = 3 ,2,1....or not divisible by 4,5,6,
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<long long> arr(n) , brr(q);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<q;i++) cin>>brr[i];
        
        int maxi = 31; // as max value of x is 30
        for(int i=0;i<q;i++){

            if(brr[i] >= maxi) continue;
            long long fac = pow(2,brr[i]);
            long long add = pow(2,brr[i]-1);

            for(int j=0;j<n;j++){
                
                if(arr[j]%fac == 0) arr[j] += add;
            }

            maxi = brr[i];
        }

        for(auto x:arr) cout<<x<<" ";
        cout<<endl;

    }

}