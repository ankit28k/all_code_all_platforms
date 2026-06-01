#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int n,int m){

    map<int,int> fq;

    for(int i=0;i<n;i++)  fq[arr[i]]++;
    
    vector<int> temp;
    for(int i=1;i<=n;i++){
        temp.push_back(fq[i]);
    }

    sort(temp.begin(),temp.end());

    int ans =0;
    while(m>0){
        
    }

    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr(m);
        for(int i=0;i<n;i++)  cin>>arr[i]; 

        cout<<fun(arr,n,m)<<endl;

    }

}