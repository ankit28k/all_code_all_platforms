#include<bits/stdc++.h>
using namespace std;

// void fun(int idx,int n,int k,int sum,vector<int>& temp,vector<vector<int>>& ans){

//     if(idx==n){
//         if(sum==k) ans.push_back(temp);
//         return;
//     }

//     int mxval = (k-sum)/(idx+1);
//     for(int i=0;i<=mxval;i++){
//         temp.push_back(i);
//         fun(idx+1,n,k,sum+ (idx+1)*i,temp,ans);
//         temp.pop_back();
//     }
// }

void fun(int idx,int n,int k,int sum,vector<int>& temp){

    if(idx==n-1){
        if((k-sum)%n==0){
            temp.push_back((k-sum)/n);
            for(int x:temp){
                cout<<x<<" ";
            }
            cout<<endl;
            temp.pop_back();
        }
        return;
    }

    int mxval = (k-sum)/(idx+1);
    for(int i=0;i<=mxval;i++){
        temp.push_back(i);
        fun(idx+1,n,k,sum+ (idx+1)*i,temp);
        temp.pop_back();
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    
    vector<int> temp;
    // vector<vector<int>> ans;
    // fun(0,n,k,0,temp,ans);

    // for(auto v:ans){
    //     for(int x:v){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }

    fun(0,n,k,0,temp);
}