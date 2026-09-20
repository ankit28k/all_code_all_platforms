#include<bits/stdc++.h>
using namespace std;

const int mod =1e9+7;
// bool isbitonic(vector<int>& arr){
//     int n = arr.size();
//     if(n<3) return false;

//     int idx =-1;
//     for(int i=0;i<n-1;i++){
//         if(arr[i]>arr[i+1]){
//             idx =i;
//             break;
//         }
//     }
//     // if(idx==-1) return false;
//     if(idx<=0) return false;
//     for(int i=idx;i<n-1;i++){
//         if(arr[i]<arr[i+1]) return false;
//     }
//     return true;
// }
// int fun(int idx,int prev,int inc,vector<int> taken,vector<int>& arr){
//     if(idx==arr.size()){
//         if(isbitonic(taken)) return 1;
//         else return 0;
//     }

//     int nt1=0,nt2=0,t1=0,t2=0;
//     if(inc==1){

//         nt1 = fun(idx+1,prev,1,taken,arr,dp);
//         nt2 = fun(idx+1,prev,0,taken,arr,dp);

//         if(prev==-1 || arr[idx]>arr[prev]){
//             taken.push_back(arr[idx]);
//             t1 = fun(idx+1,idx,1,taken,arr,dp);
//             t2 = fun(idx+1,idx,0,taken,arr,dp);
//         }
        
//     }

//     else{
//         nt2 = fun(idx+1,prev,0,taken,arr,dp);

//         if(prev==-1 || arr[idx]<arr[prev]){
//             taken.push_back(arr[idx]);
//             t2 = fun(idx+1,idx,0,taken,arr,dp);
//         }
        
//     }

//     return t1+t2+nt1+nt2;
// }

int fun(int idx,int prev,int inc,int taken,vector<int>& arr,map< pair< pair<int,int> , pair<int,int>> , long long>& dp){
    if(idx==arr.size()){
        if(taken>=3 && inc==0) return 1;
        else return 0;
    }
    if( dp.find({{idx,prev},{inc,taken}}) != dp.end() ) return dp[{{idx,prev},{inc,taken}}];

    long long nt1=0,nt2=0,t1=0,t2=0;
    if(inc==1){

        nt1 = fun(idx+1,prev,1,taken,arr,dp);

        //causes overcounting
        //if(taken>=2) nt2 = fun(idx+1,prev,0,taken,arr,dp); // making atleast 2 elements increasing 

        if(prev==-1 || arr[idx]>arr[prev]){
            t1 = fun(idx+1,idx,1,taken+1,arr,dp);
            if(taken +1 >=2) t2 = fun(idx+1,idx,0,taken+1,arr,dp); // making atleast 2 elements increasing 
        }
        
    }

    else{
        nt2 = fun(idx+1,prev,0,taken,arr,dp);

        if(prev==-1 || arr[idx]<arr[prev]){
            t2 = fun(idx+1,idx,0,taken+1,arr,dp);
        }
        
    }

    return dp[{{idx,prev},{inc,taken}}] = (t1+t2+nt1+nt2)%mod;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    map< pair< pair<int,int> , pair<int,int>> , long long> dp;
    // vector<int> temp = {};
    // cout<<fun(0,-1,1,temp,arr,dp);

    cout<<fun(0,-1,1,0,arr,dp);

}