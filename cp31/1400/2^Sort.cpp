#include<bits/stdc++.h>
using namespace std; 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int prev =0;
        vector<int> temp(n);

        temp[0] =0;

        for(int i=1;i<n;i++){
            if(arr[i]*2 > arr[i-1]) temp[i] = prev;
            else{
                prev =i;
                temp[i] = prev;
            }
        }

        int cnt=0 ;
        for(int i=0;i<n;i++){
            if(i-temp[i] + 1 >= k+1) cnt++;
        }

        cout<<cnt<<endl;
    }

}
 