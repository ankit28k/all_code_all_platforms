#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0;i<n;i++){
            arr[i] = i+1;
        }
        reverse(arr.begin(),arr.end());
        // arr[0] = n-1;
        // arr[1] = n;

        // for(int i=2;i<n-1;i+=2){
        //     arr[i] = arr[i-2] -2;
        //     arr[i+1] = arr[i-1] -2;
        // }

        // if(n%2 != 0) arr[n-1] = 1;

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

}