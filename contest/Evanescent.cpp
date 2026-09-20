#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;;
        cin>>s;

        vector<pair<char,int>> arr;
        int i=0;
        while(i<n){
            char c= s[i];
            int temp=0;
            while(s[i]==c){
                temp++;
                i++;
            }
            arr.push_back({c,temp});
        }

        
        int nr =arr.size();
        int ans=nr;
        for(int i=1;i<nr-1;i++){
            if(arr[i].second==1){
                if(arr[i-1].first == arr[i+1].first) ans = min(ans,nr-2);
                else ans = min(ans,nr-1);
            }
        }

        cout<<ans<<endl;

    }

}