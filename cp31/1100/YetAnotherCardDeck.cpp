#include<bits/stdc++.h>
using namespace std;

void fun(vector<int>& arr,int pos){

    for(int i=1;i<=50;i++){ 

        // less than pos...as    2 1 1 4 3 3 1 -> 3 2 1 1 4 3 1 -> 2 3 1 1 4 3 1....only position less than that element's increment like 2...and stays same for greater position elements like 1 ,4 

        if(arr[i] != -1 && arr[i]<pos) arr[i]++;
    }
}

int main(){
    int n,q;
    cin>>n>>q;

    vector<int> arr(51,-1); 

    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(arr[x] == -1) arr[x] = i+1;
    }

    vector<int> qrr(q) , ans;
    for(int i=0;i<q;i++) cin>>qrr[i]; 
    
    for(int i=0;i<q;i++){

        int pos = arr[ qrr[i] ];

        ans.push_back( arr[ qrr[i]]);
        fun(arr,pos);
        arr[ qrr[i]] =1;
    } 

    for(int x:ans) cout<<x<<" ";
    cout<<endl;

}