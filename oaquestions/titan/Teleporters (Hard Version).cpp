#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int n,int c){

    vector<pair<int,int>> templ ,temp;
    for(int i=1;i<=n;i++){
        int curr = arr[i] + i;
        templ.push_back({curr,i});
    }
    for(int i=1;i<=n;i++){
        int curr = arr[i] + min(i,n+1-i);
        temp.push_back({curr,i});
    }

    sort(templ.begin(),templ.end());
    sort(temp.begin(),temp.end());

    vector<bool> vis(n+2,false);

    int ans=0;
    if(templ.size()>0){
        int idx = templ[0].second;
        vis[idx] = true;
        if(c>=templ[0].first) {
            c-=templ[0].first;
            ans++;
        }
        else return 0;
    }
    
    for(int i=0;i<n;i++){
        int idx = temp[i].second;
        if(!vis[idx]){
            vis[idx] = true;
            if(c>=temp[i].first) {
                c-=temp[i].first;
                ans++;
            }
            else return ans;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> arr(n+2);
        for(int i=1;i<=n;i++) cin>>arr[i];
        cout<<fun(arr,n,c)<<endl;
    }

}