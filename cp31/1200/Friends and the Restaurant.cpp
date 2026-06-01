#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int n){

    if(arr[n-1] <0 || arr[n-1]+arr[n-2]<0) return 0;

    int cnt=0;
    for(int i=0,j=n-1;i<j;){
        if(arr[i]>=0){
            cnt++;
            i++;
            j--;
        }

        else{
            if(arr[i]+arr[j]>=0){
                cnt++;
                i++;
                j--;
            }

            else i++;
        }
    }

    return cnt;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n),brr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];

        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[i] = brr[i] - arr[i];
        }

        sort(temp.begin(),temp.end());
        cout<<fun(temp,n)<<endl;
        
    }

}