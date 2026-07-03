#include<bits/stdc++.h>
using namespace std;


string fun(vector<long long>& arr,int n){
    
    long long sum=0,maxi=0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
        sum+=arr[i];
    }

    if(sum%2 !=0 ) return "NO";
    if(sum-maxi < maxi) return "NO";
    return "YES";
}

int main(){  

    int n;
    cin>>n;

    vector<long long> arr(n);
    for(int i=0;i<n;i++)  cin>>arr[i]; 
    cout<<fun(arr,n)<<endl;
 
}