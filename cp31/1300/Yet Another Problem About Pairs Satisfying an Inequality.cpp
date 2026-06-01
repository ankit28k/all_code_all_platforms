#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 

        vector<int> val , idx;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x; 
            if(i+1>x) {
                val.push_back(x);
                idx.push_back(i+1);
            }   
        }  
        
        sort(idx.begin(),idx.end());

        long long ans=0;
        for(int i=0;i<val.size();i++){
            int it = lower_bound(idx.begin(),idx.end(),val[i]) - idx.begin();
            ans += it;
        }

        cout<<ans<<endl;
        

         
    }

}