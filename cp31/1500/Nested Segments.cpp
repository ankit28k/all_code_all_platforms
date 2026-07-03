#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0]) return a[1] > b[1];   // second: high → low
    return a[0] < b[0];       // first: low → high
}

pair<int,int> fun(vector<vector<int>>& arr,int n){

    sort(arr.begin(),arr.end(),cmp);
    vector<int> smin(n);
    smin[n-1] = arr[n-1][1];
    for(int i=n-2;i>=0;i--) smin[i] = min(smin[i+1],arr[i][1]);

    
    for(int i=0;i<n-1;i++){

        if(arr[i][1]<arr[i+1][0]) continue;
        
        else if(arr[i][1]>=arr[i+1][0]){

            if(smin[i]<arr[i][1]){
                int ini = arr[i][0] , fin = arr[i][1];
                int j = i+1;
                while(j<n && fin < arr[j][1]){
                    if(arr[j][0]<=ini) return {arr[j][2],arr[i][2]};
                    else j++;
                }
                return {arr[j][2],arr[i][2]};
            }
            
            if(arr[i][1]>=arr[i+1][1]) return {arr[i+1][2],arr[i][2]};            
            
        }
    }

    return {-1,-1};
}

int main(){ 
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[i] = {x,y,i+1};
    }

    pair<int,int> ans = fun(arr,n);
    cout<<ans.first<<" "<<ans.second<<endl;
        
    

}