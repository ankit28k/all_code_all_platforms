#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n),ans(n);
        for(int i=1;i<n;i++) cin>>arr[i];

        bool flag = false;

        if(arr[1]>arr[2]) {
            ans[0] = arr[1];
            ans[1] =0;
            ans[2] = arr[2];
            flag = true;
        }

        else {
            ans[0] = arr[1];
            ans[1] = arr[1];
            ans[2] = arr[2];
        }

        int i;
        for(i=3;i<n;i++){

            if(flag){
                ans[i] = arr[i];
            }

            else{
                if(i<n-1){
                    if(arr[i]>arr[i+1]){
                        ans[i] = arr[i];
                        ans[i+1] = 0;
                        ans[i+2] = arr[i+1];
                        flag = true;
                    }
                    else ans[i] = arr[i];
                }
                
                else ans[i] = arr[i];
            }
            
        }


        for(int x :ans) cout<<x<<" ";
        cout<<endl;
    }

}