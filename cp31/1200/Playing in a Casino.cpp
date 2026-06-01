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

        long long sum =0;
        for(int c=0;c<m;c++){

            vector<int> temp;
            for(int r = 0;r<n;r++) temp.push_back(arr[r][c]);
            sort(temp.begin(),temp.end());

            for(int i=0;i<n;i++){
                // long long smaller_el = i;
                // long long bigger_el = n-1-i;

                // sum += temp[i]*smaller_el - temp[i]*bigger_el;

                sum += temp[i]*1LL*(2*i - n + 1);
                 
            }
        }

        cout<<sum<<endl;
    }

}