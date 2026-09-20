#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        if(k<n || k>=2*n){
            cout<<-1<<endl;
            continue;
        }

        int val = k-n;
        vector<vector<int>> arr(n,vector<int>(n,0));
        int cval = 1;
        for(int i=0;i<=val;i++) {
            arr[0][i] = cval;
            cval++;
        }
        for(int i=1;i<n;i++) {
            arr[i][i] =cval;
            cval++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==0){
                    arr[i][j] =cval;
                    cval++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }

}