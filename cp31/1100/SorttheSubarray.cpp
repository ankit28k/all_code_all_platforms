#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n) , brr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];
         
        int l=0,r=n-1;

        for(int i=0;i<n;i++){
            if(arr[i]!=brr[i]){
                l=i;
                break;
            }
        }

        for(int i=l;i>=0;i--){
            if(i==0){
                l=0;
                break;
            }
            if(brr[i-1]>brr[i]){
                l=i;
                break;
            }
        }

        for(int i=n-1;i>=l;i--){
            if(arr[i]!=brr[i]){
                r=i;
                break;
            }
        }

        for(int i=r;i<n;i++){
            if(i==n-1){
                r=n-1;
                break;
            }
            if(brr[i]>brr[i+1]){
                r=i;
                break;
            }
        }

        cout<<l+1<<" "<<r+1<<endl;
    }

}