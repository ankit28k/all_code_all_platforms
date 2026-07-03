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

                // can use any combination of powers not only single power

                
                int inc = arr[i-1] - arr[i];
                int powreq = log2(inc) ;

                arr[i] = arr[i-1]; // as we can make any number with summation of powers of 2
                x = max(x,powreq + 1);
                
                // if(x >= powreq+1) {
                    
                    
                //     arr[i] += pow(2,powreq);
                // }
                // else {
                    
                //     x = powreq + 1; // x + (powreq + 1 -x);
                //     arr[i] += pow(2,x-1);

                // }
            }
                 
            
        }

        cout<<x<<endl;
    }

}