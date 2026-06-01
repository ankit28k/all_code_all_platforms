#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<vector<int>> arr(n);
        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            vector<int> temp(m);

            for(int j=0;j<m;j++) cin>>temp[j];

            sort(temp.begin(),temp.end());

            arr[i] = temp;
        }

        
        int minimum = INT_MAX , secondmin=INT_MAX ;
        long long secondmin_sum = 0;
        for(int i=0;i<n;i++){
            minimum = min(minimum,arr[i][0]);
            secondmin =  min(secondmin,arr[i][1]);
            secondmin_sum += arr[i][1];
        }
        long long ans = secondmin_sum - secondmin + minimum;
        cout<<ans<<endl;
        
    }

}