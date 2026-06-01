#include<bits/stdc++.h>
using namespace std;

bool poss(vector<int>& arr,int h,int n,int idx){

    sort(arr.begin(),arr.begin()+idx+1);

    int sum1=0 , sum2 =0;
    for(int i=idx;i>=0;i-=2){
        sum1+= arr[i];
    }

    for(int i=idx-1;i>=0;i-=2){
        sum2+= arr[i];
    }
    return sum1<=h && sum2<=h;

}

int main(){
    
    int n, h;
    cin>>n>>h;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i]; 
    
    int ans = 0;

    for(int i=0;i<n;i++){
        if(poss(arr,h,n,i))  ans = max(ans,i+1);
        else break;
    }
    
    cout<<ans<<endl;

}