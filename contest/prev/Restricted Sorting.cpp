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

        vector<int> temp = arr;
        sort(temp.begin(),temp.end());

        int ans = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==temp[i]) continue;
            else{
                ans = max(ans,abs(arr[i]-temp[i]));
            }
        }
        if(ans!=0) cout<<ans<<endl;
        else cout<<-1<<endl;
    }

}