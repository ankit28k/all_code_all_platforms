#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        if(arr[n-2]>arr[n-1]){
            cout<<-1<<endl;
            continue;
        }

        vector<vector<int>> ans;
        int cnt=0,np =-1;
        if(arr[n-1]>=0) np =n-1;

        // do dynamic changing as ex-5 4 2 10 ....np becomes 2 pointing to 2....but 4>2 hence arr[1] = arr[2]-arr[np] = arr[2]-arr[2]...
        //but its given x<y<z...and here y==z
        //if(arr[n-2]>0) np=n-2;
        for(int i=n-3;i>=0;i--){
            if(arr[i]>arr[i+1]){
                if(np==-1){
                    cnt = n+1;
                    break;
                }
                arr[i] = arr[i+1]-arr[np];
                ans.push_back({i+1,i+2,np+1});
                cnt++;
                //if(arr[i]>0) np = i;
            }
        }

        int nt=ans.size();
        if(cnt>n){
            cout<<-1<<endl;
            continue;
        }
        cout<<nt<<endl;
        for(int i=0;i<nt;i++){
            for(int j=0;j<3;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }

}