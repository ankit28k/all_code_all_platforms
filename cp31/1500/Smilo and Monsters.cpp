#include<bits/stdc++.h>
using namespace std;

long long fun(vector<int>& arr,int n){

    long long ans =0,temp=0;

    int i=0,j=n-1;
    while(i<j){
        temp+=arr[i];
        if(temp>=arr[j]){
            ans+=temp+1;
            temp =0;
            j--;
        }

        if(i+1==j && temp<arr[j]) {
            ans += arr[j]+1; //temp + 1 + arr[j]-temp;
            break;
        }
        i++;
    }

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

        sort(arr.begin(),arr.end()); 
        cout<<fun(arr,n)<<endl;
    }

}