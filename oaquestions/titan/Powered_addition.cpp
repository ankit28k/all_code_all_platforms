#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int x =0;
        for(int i=1;i<n;i++){ 

            if(arr[i]<arr[i-1]){
                
                int inc = arr[i-1] - arr[i];
                int powreq = log2(inc) ;

                arr[i] =arr[i-1]; 
                x = max(x,powreq + 1);
            }
                 
            
        }

        cout<<x<<endl;
    }

}