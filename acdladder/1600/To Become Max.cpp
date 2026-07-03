#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int n,int k){

    if(n==1) return arr[0];

    vector<int> temp;
    int ans = arr[n-1];
    for(int i=0;i<n-1;i++){
        if(arr[i]<=arr[i+1]) temp.push_back(i);
        ans = max(ans,arr[i]);
    }

    int nt = temp.size();
    for(int i=0;i<nt;i++){
        int j = temp[i] , nk = k,prev = arr[temp[i]+1];
        while(j>=0 && nk>0){
            if(arr[j]>prev) break;

            int val = prev + 1 - arr[j];
            if(nk>=val) {
                nk -= val;
                prev++;
                ans = max(ans,prev);
            }

            else if(nk<val) break;
            j--;

        }
    }
    
    return ans;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        cout<<fun(arr,n,k)<<endl;

        
    }

}