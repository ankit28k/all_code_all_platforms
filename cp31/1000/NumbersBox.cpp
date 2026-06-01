#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }

        int mini = INT_MAX , ncnt=0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mini = min(mini,abs(arr[i][j]));
                if(arr[i][j]<0) ncnt++;
                sum += abs(arr[i][j]);
            }
            
        }

        if(ncnt%2==0) cout<<sum<<endl;
        else cout<<sum-2*mini<<endl;


    }

}
 