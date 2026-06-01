#include<bits/stdc++.h>
using namespace std; 

 
int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
 
    
    int ans=0;
    long long sum =0,temp=0;

    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum<0){
            sum -= arr[i]; 
        }

        else ans++;

    }

    cout<<ans<<endl;

}