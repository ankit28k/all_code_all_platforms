#include<bits/stdc++.h>
using namespace std;

bool checkp(vector<int>& arr,int n,int l,int r,int rele){

    for(int i=l,j=r;i<j;){ 
        
        if(arr[i]!=arr[j]){

            if(arr[i]==rele) i++;
            else if(arr[j]==rele) j--;
            else return false;
        }

        else{
            i++;
            j--;
        }
        
    }

    return true;
}

string fun(vector<int>& arr,int n){

    //int rele = -1;

    for(int i=0,j=n-1;i<j;){

        if(arr[i] != arr[j] ){ //&& rele == -1
            if(checkp(arr,n,i,j,arr[i]) || checkp(arr,n,i,j,arr[j])) return "YES";
            else return "NO";
            // rele =arr[i];
            // i++;
            
        }

        // else if(arr[i]!=arr[j]){

        //     if(arr[i]==rele) i++;
        //     else if(arr[j]==rele) j--;
        //     else return "NO";
        // }

        else{
            i++;
            j--;
        }
        
    }

    return "YES";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<fun(arr,n)<<endl;

    }

}