#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        long long maxi = arr[0],cnt=0;
        for(int i=0;i<n;i++){

            if(i%2==0) {
                maxi = max(maxi,arr[i]);
                continue;
            }

            // if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) {
            //     maxi = max(maxi,arr[i]);
            //     continue;
            // }

            arr[i] = max(arr[i],maxi);

            if(arr[i-1]>=arr[i]){
                long long k = abs(arr[i] - arr[i-1]) +1;
                cnt += k;
                arr[i-1]-=k;
            }

            if(i+1<n){//last idx
                
                maxi = max(arr[i+1],maxi);

                if(arr[i+1]>=arr[i]){
                    long long k = abs(arr[i] - arr[i+1]) +1;
                    cnt += k;
                    arr[i+1]-=k;
                }

            }
            
            maxi = max(maxi,arr[i]);
                
            
        }

        cout<<cnt<<endl;
    }

}