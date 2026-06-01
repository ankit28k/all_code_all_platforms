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
 
        int cnt=1;
        int prev = arr[0];
        for(int i=1;i<n;i++){
            
            
            if(prev <= arr[i]-1) continue; 
            
            else {
                cnt++;
                prev = arr[i];
            }
        }

        cout<<cnt<<endl;
    }

}