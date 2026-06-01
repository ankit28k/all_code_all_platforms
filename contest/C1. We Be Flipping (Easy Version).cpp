#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<int> ans;
        int f=0;
        
        for(int i=n-1;i>=0;i--){

            int cs;
            if(arr[i]>0) cs =1;
            else cs = -1;

            if(f%2 !=0) cs*=-1;
            if(cs>0){
                ans.push_back(i+1);
                f++;
            }
        }

        if(ans.size()==0){
            cout<<0<<endl;
            continue;
        }
        cout<<ans.size()<<endl;
        for(int x:ans) cout<<x<<" ";
        cout<<endl;
    }

}