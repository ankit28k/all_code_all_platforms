#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> arr(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++){
                cin>>arr[i][j];
            }
        }
        
        int k = 2*n;
        vector<int> ans(k + 1);

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++){
                int k = i + j ;
                ans[k] = arr[i][j];
            }
        }

        int sum = accumulate(ans.begin(),ans.end(),0);
        

        ans[1] = k*(k+1)/2 - sum;

        for(int i=1;i<=k;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

}