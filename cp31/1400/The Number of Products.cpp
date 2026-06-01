#include<bits/stdc++.h>
using namespace std;

int fun1(vector<int>& arr,int n){
    
    int l=0,r=0;
    int ans = 0, neg =0;
    while(r<n){

        if(arr[r]<0) {
            neg++;
            if(neg%2 !=0) ans++;
        }

        r++;

        while(neg%2 == 0 && l<=r){
            
            if(arr[l] <0) neg--;
            l++;
            ans++;
        }

    }

    return ans;
}

int fun2(vector<int>& arr,int n){

    int l=0,r=0;
    int ans = 0, neg =0;

    while(r<n){

        if(arr[r]<0) {
            neg++;
            if(neg%2 ==0) ans++;
        }

        r++;

        while(neg%2 != 0 && l<=r){
            
            if(arr[l] <0) neg--;
            l++;
            ans++;
        }

    }

    return ans;
}

int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<fun1(arr,n)<<" "<<fun2(arr,n)<<endl;
    

}