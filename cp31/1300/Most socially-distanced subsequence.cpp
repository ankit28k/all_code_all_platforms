#include<bits/stdc++.h>
using namespace std;

//similar to contrast value 1200
vector<int> fun(vector<int>& arr,int n){
    
    vector<int> ans; 

    int i=n-1;
    while(i>0){
        if(arr[i] > arr[i-1]){

            ans.push_back(arr[i]);

            while(i>0 && arr[i] > arr[i-1]){
                i--;
            }
            
        }

        else if(arr[i] < arr[i-1]){

            ans.push_back(arr[i]);

            while(i>0 && arr[i] < arr[i-1]){
                i--;
            }
            
        }
    }

    ans.push_back(arr[i]);
    reverse(ans.begin(),ans.end());

    return ans;


}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i]; 

        vector<int> ans = fun(arr,n);
        cout<<ans.size()<<endl;
        for(int x:ans) cout<<x<<" ";
        cout<<endl;
    }

} 