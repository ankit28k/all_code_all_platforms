#include<bits/stdc++.h>
using namespace std;

int fun(int n,int m,int ta,int tb,int k,vector<int>& arr,vector<int>& brr){

    if(k>=n || k>=m) return -1;
    
    int ans=-1;

    // int i=0,j=0;
    // while(i<n){
    //     int idx = lower_bound(brr.begin()+j,brr.end(),arr[i]) - brr.begin();
    //     if(idx==m) return -1;
    //     int temp = brr[idx]+tb;
    //     if(k<=0){
    //         ans = temp;
    //         break;
    //     }
    //     else{
    //         if(brr[idx]>arr[i]) j=idx+1;
    //         else i++;
    //         k--;
    //     }
    // }

    //delete first i flight from A->B then k-i flights from B->C..
    for(int i=0;i<=k;i++){
        int idx = lower_bound(brr.begin(),brr.end(),arr[i]) - brr.begin();
        if(idx + (k-i) >= m) return -1; 
        ans = max(ans,brr[idx+(k-i)] + tb);
    }
    return ans;
}
int main(){
    int n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    vector<int> arr(n),brr(m);
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr[i]=x+ta;
    }
    for(int i=0;i<m;i++) cin>>brr[i];

    sort(arr.begin(),arr.end());
    cout<<fun(n,m,ta,tb,k,arr,brr)<<endl;
    

}